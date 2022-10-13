#include <Python.h>
#include "Fonctionnalité.h"


static PyObject* Play(PyObject* self, PyObject* args)
{
    
    Fonctionnalité* fonction = &Fonctionnalité::GetInstance();
    if (fonction->m_state == STATE_PAUSED)
    {
        fonction->Play();
    }

    /*if (SUCCEEDED(fonction->hr))
    {
        // Wait for completion.
        long evCode;
        fonction->pEvent->WaitForCompletion(INFINITE, &evCode);

        // Note: Do not use INFINITE in a real application, because it
        // can block indefinitely.
    }*/
    return Py_BuildValue("i", 0);
}


static PyObject* Pause(PyObject* self, PyObject* args)
{
    Fonctionnalité* fonction = &Fonctionnalité::GetInstance();
    fonction->m_state = STATE_RUNNING;
    if (fonction->m_state == STATE_RUNNING)
    {
        fonction->Pause();
    }
    return Py_BuildValue("i", 0);
}


static PyObject* FastForward(PyObject* self, PyObject* args)
{
    Fonctionnalité* fonction = &Fonctionnalité::GetInstance();

    fonction->FastForward();
    
    return Py_BuildValue("i", 0);
}

static PyObject* Restart(PyObject* self, PyObject* args)
{
    Fonctionnalité* fonction = &Fonctionnalité::GetInstance();

    fonction->Restart();

    return Py_BuildValue("i", 0);
}

static PyObject* Quitter(PyObject* self, PyObject* args)
{
    Fonctionnalité* fonction = &Fonctionnalité::GetInstance();

    fonction->Quitter();

    return Py_BuildValue("i", 0);
}

static PyMethodDef methods[] = {

        { "Play", Play, METH_NOARGS,
          "Generate random number betweeen 0-9" },
        { "Pause", Pause, METH_NOARGS,
          "Generate random number betweeen 0-9" },
        { "Restart", Restart, METH_NOARGS,
          "Generate random number betweeen 0-9" },
        { "FastForward", FastForward, METH_NOARGS,
          "Generate random number betweeen 0-9" },
        { "Quitter", Quitter, METH_NOARGS,
          "Generate random number betweeen 0-9" },
        { NULL, NULL, 0, NULL }

};

static struct PyModuleDef Lab2 =
{
    PyModuleDef_HEAD_INIT,
    "Lab2", /* name of module */
    "",          /* module documentation, may be NULL */
    -1,          /* size of per-interpreter state of the module, or -1 if the module keeps state in global variables. */
    methods
};

PyMODINIT_FUNC PyInit_Lab2(void)
{
    return PyModule_Create(&Lab2);
}
