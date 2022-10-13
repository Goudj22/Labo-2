#include "Fonctionnalit�.h"

using namespace std;

//Fonctionnalit�* fonction ;

Fonctionnalit�::Fonctionnalit�()
{
    // Initialize the COM library.
    hr = CoInitialize(NULL);
    if (FAILED(hr))
    {
        printf("ERROR - Could not initialize COM library");
    }

    // Create the filter graph manager and query for interfaces.
    hr = CoCreateInstance(CLSID_FilterGraph, NULL, CLSCTX_INPROC_SERVER,
        IID_IGraphBuilder, (void**)&pGraph);
    if (FAILED(hr))
    {
        printf("ERROR - Could not create the Filter Graph Manager.");
    }

    // Build the graph. IMPORTANT: Change this string to a file on your system.
    hr = pGraph->RenderFile(L"C:\\Users\\fbgoudiaby\\Downloads\\Lab2 (1)\\Lab2\\Lab2\\Example.avi", NULL);

    hr = pGraph->QueryInterface(IID_IMediaControl, (void**)&pControl);
    hr = pGraph->QueryInterface(IID_IMediaEvent, (void**)&pEvent);
    hr = pGraph->QueryInterface(IID_IMediaSeeking, (void**)&pSeek);
}

Fonctionnalit�::~Fonctionnalit�()
{

}

void Fonctionnalit�::Play()
{
    if (m_state != STATE_PAUSED && m_state != STATE_STOPPED)
    {
        return;
    }

    hr = pControl->Run();
    if (SUCCEEDED(hr))
    {
        m_state = STATE_RUNNING;
    }
}

void Fonctionnalit�::Pause()
{
    if (m_state != STATE_RUNNING)
    {
        return;
    }

    hr = pControl->Pause();
    if (SUCCEEDED(hr))
    {
        m_state = STATE_PAUSED;
    }
}

void Fonctionnalit�::FastForward()
{
    if (m_state != STATE_RUNNING)
    {
        return;
    }

    hr = pSeek->SetRate(2.0);
}

void Fonctionnalit�::Restart()
{
    if (m_state == STATE_RUNNING)
    {
        Fonctionnalit�::Pause();
    }
    rtNow = 2 * ONE_SECOND;
    hr = pSeek->SetPositions(&rtNow, AM_SEEKING_AbsolutePositioning, NULL, AM_SEEKING_NoPositioning);
    hr = pControl->Run();
}


void Fonctionnalit�::Quitter()
{
    if (m_state != STATE_RUNNING && m_state != STATE_PAUSED)
    {
        return;
    }

    hr = pControl->Stop();
    if (SUCCEEDED(hr))
    {
        m_state = STATE_STOPPED;
    }

    pControl->Release();
    pEvent->Release();
    pGraph->Release();
    CoUninitialize();
    //exit ;
}
