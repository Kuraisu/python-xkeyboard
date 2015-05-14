// xkeyboard-mod.cpp
// Python binding module for XKeyboard class
// Copyright (C) 2015 by Aleksey Yermakov <jp.kuraisu@gmail.com>
//
// This program is free software; you can redistribute it and/or modify it
// under the terms of the GNU General Public License as published by the Free
// Software Foundation; either version 2 of the License, or (at your option)
// any later version.
//

#include <Python.h>
#include <structmember.h>

#include "XKeyboard.h"

typedef struct {
    PyObject_HEAD
    XKeyboard *xkb_obj;
} xkeyboard_XKeyboard;

static void
xkeyboard_XKeyboard_dealloc(xkeyboard_XKeyboard* self)
{
    if(self->xkb_obj != NULL)
        delete self->xkb_obj;
}

static PyObject *
xkeyboard_XKeyboard_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    xkeyboard_XKeyboard *self;

    self = (xkeyboard_XKeyboard *)type->tp_alloc(type, 0);
    if (self != NULL) {
        self->xkb_obj = NULL;
    }

    return (PyObject *)self;
}

static int
xkeyboard_XKeyboard_init(xkeyboard_XKeyboard *self, PyObject *args, PyObject *kwds)
{
    try {
        self->xkb_obj = new XKeyboard();
    }
    catch (std::bad_alloc& ba) {
        PyErr_SetString(PyExc_MemoryError, "not enough memory for object allocation");
        return -1;
    }

    return 0;
}

//-----------
// Methods

static PyObject *
xkeyboard_groupCount(PyObject *self, PyObject *args)
{
    XKeyboard xkb;
    return PyInt_FromLong(xkb.groupCount());
}

static PyObject *
xkeyboard_groupNames(PyObject *self, PyObject *args)
{
    XKeyboard xkb;
    
    StringVector elements = xkb.groupNames();
    PyObject* tuple = PyTuple_New(elements.size());
    int i = 0;

    for(StringVector::const_iterator element = elements.begin(); element != elements.end(); ++element, ++i) {
        PyTuple_SET_ITEM(tuple, i, PyString_FromString((*element).c_str()));
    }
    
    return tuple;
    //return PyString_FromString(xkb.currentGroupName().c_str());
    //Py_RETURN_NONE;
}

static PyObject *
xkeyboard_groupSymbols(PyObject *self, PyObject *args)
{
    XKeyboard xkb;
    
    StringVector elements = xkb.groupSymbols();
    PyObject* tuple = PyTuple_New(elements.size());
    int i = 0;

    for(StringVector::const_iterator element = elements.begin(); element != elements.end(); ++element, ++i) {
        PyTuple_SET_ITEM(tuple, i, PyString_FromString((*element).c_str()));
    }
    
    return tuple;
}

static PyObject *
xkeyboard_groupVariants(PyObject *self, PyObject *args)
{
    XKeyboard xkb;
    
    StringVector elements = xkb.groupVariants();
    PyObject* tuple = PyTuple_New(elements.size());
    int i = 0;

    for(StringVector::const_iterator element = elements.begin(); element != elements.end(); ++element, ++i) {
        PyTuple_SET_ITEM(tuple, i, PyString_FromString((*element).c_str()));
    }
    
    return tuple;
}

static PyObject *
xkeyboard_currentGroupNum(PyObject *self, PyObject *args)
{
    XKeyboard xkb;
    return PyInt_FromLong(xkb.currentGroupNum());
}

static PyObject *
xkeyboard_currentGroupName(PyObject *self, PyObject *args)
{
    XKeyboard xkb;
    return PyString_FromString(xkb.currentGroupName().c_str());
}

static PyObject *
xkeyboard_currentGroupSymbol(PyObject *self, PyObject *args)
{
    XKeyboard xkb;
    return PyString_FromString(xkb.currentGroupSymbol().c_str());
}

static PyObject *
xkeyboard_currentGroupVariant(PyObject *self, PyObject *args)
{
    XKeyboard xkb;
    return PyString_FromString(xkb.currentGroupVariant().c_str());
}

static PyObject *
xkeyboard_setGroupByNum(PyObject *self, PyObject *args)
{
    XKeyboard xkb;
    int index;
    
    if (!PyArg_ParseTuple(args, "i", &index))
        return NULL;
    
    if (xkb.setGroupByNum(index)) {
        Py_RETURN_TRUE;
    }

    Py_RETURN_FALSE;
}

static PyObject *
xkeyboard_changeGroup(PyObject *self, PyObject *args)
{
    XKeyboard xkb;
    int index;
    
    if (!PyArg_ParseTuple(args, "i", &index))
        return NULL;
    
    if (xkb.changeGroup(index)) {
        Py_RETURN_TRUE;
    }

    Py_RETURN_FALSE;
}

// ----------
// Lock modifiers

static PyObject *
xkeyboard_capsLockState(PyObject *self, PyObject *args)
{
    XKeyboard xkb;
    
    if(xkb.capsLockState()) {
        Py_RETURN_TRUE;
    }
    
    Py_RETURN_FALSE;
}

static PyObject *
xkeyboard_numLockState(PyObject *self, PyObject *args)
{
    XKeyboard xkb;
    
    if(xkb.numLockState()) {
        Py_RETURN_TRUE;
    }
    
    Py_RETURN_FALSE;
}

static PyObject *
xkeyboard_scrollLockState(PyObject *self, PyObject *args)
{
    XKeyboard xkb;
    
    if(xkb.scrollLockState()) {
        Py_RETURN_TRUE;
    }
    
    Py_RETURN_FALSE;
}

static PyMethodDef xkeyboardMethods[] = {
    {NULL, NULL, 0, NULL}        /* Sentinel */
};

static PyMethodDef XKeyboard_methods[] = {
    {"groupCount",  xkeyboard_groupCount, METH_VARARGS, "Total layout groups count."},
    {"groupNames",  xkeyboard_groupNames, METH_VARARGS, "Names of groups."},
    {"groupSymbols",  xkeyboard_groupSymbols, METH_VARARGS, "Symbol names of groups."},
    {"groupVariants",  xkeyboard_groupVariants, METH_VARARGS, "Variants of groups."},
    {"currentGroupNum",  xkeyboard_currentGroupNum, METH_VARARGS, "Current selected group index."},
    {"currentGroupName",  xkeyboard_currentGroupName, METH_VARARGS, "Current selected group name."},
    {"currentGroupSymbol",  xkeyboard_currentGroupSymbol, METH_VARARGS, "Current selected group symbol name."},
    {"currentGroupVariant",  xkeyboard_currentGroupVariant, METH_VARARGS, "Current selected group variant."},
    {"setGroupByNum",  xkeyboard_setGroupByNum, METH_VARARGS, "Change current active group by index."},
    {"changeGroup",  xkeyboard_changeGroup, METH_VARARGS, "Change current active group incremently."},
    {"capsLockState",  xkeyboard_capsLockState, METH_VARARGS, "Caps Lock state."},
    {"numLockState",  xkeyboard_numLockState, METH_VARARGS, "Num Lock state."},
    {"scrollLockState",  xkeyboard_scrollLockState, METH_VARARGS, "Scroll Lock state."},
    {NULL, NULL, 0, NULL}        /* Sentinel */
};

static PyTypeObject xkeyboard_XKeyboardType = {
    PyObject_HEAD_INIT(NULL)
    0,                         /*ob_size*/
    "xkeyboard.XKeyboard",     /*tp_name*/
    sizeof(xkeyboard_XKeyboard), /*tp_basicsize*/
    0,                         /*tp_itemsize*/
    (destructor)xkeyboard_XKeyboard_dealloc, /*tp_dealloc*/
    0,                         /*tp_print*/
    0,                         /*tp_getattr*/
    0,                         /*tp_setattr*/
    0,                         /*tp_compare*/
    0,                         /*tp_repr*/
    0,                         /*tp_as_number*/
    0,                         /*tp_as_sequence*/
    0,                         /*tp_as_mapping*/
    0,                         /*tp_hash */
    0,                         /*tp_call*/
    0,                         /*tp_str*/
    0,                         /*tp_getattro*/
    0,                         /*tp_setattro*/
    0,                         /*tp_as_buffer*/
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE, /*tp_flags*/
    "XKeyboard objects",       /* tp_doc */
    0,		                   /* tp_traverse */
    0,		                   /* tp_clear */
    0,		                   /* tp_richcompare */
    0,		                   /* tp_weaklistoffset */
    0,		                   /* tp_iter */
    0,		                   /* tp_iternext */
    XKeyboard_methods,         /* tp_methods */
    0,                         /* tp_members */
    0,                         /* tp_getset */
    0,                         /* tp_base */
    0,                         /* tp_dict */
    0,                         /* tp_descr_get */
    0,                         /* tp_descr_set */
    0,                         /* tp_dictoffset */
    (initproc)xkeyboard_XKeyboard_init, /* tp_init */
    0,                         /* tp_alloc */
    xkeyboard_XKeyboard_new,   /* tp_new */
};

PyMODINIT_FUNC
initxkeyboard(void)
{
    PyObject *m;

    m = Py_InitModule("xkeyboard", xkeyboardMethods);
    if (m == NULL)
        return;

    xkeyboard_XKeyboardType.tp_new = PyType_GenericNew;
    if (PyType_Ready(&xkeyboard_XKeyboardType) < 0)
        return;

    Py_INCREF(&xkeyboard_XKeyboardType);
    PyModule_AddObject(m, "XKeyboard", (PyObject *)&xkeyboard_XKeyboardType);
}
