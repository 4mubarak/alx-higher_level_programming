#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <listobject.h>

/**
 * print_python_list_info - Prints information about a Python list.
 * @p: Pointer to the Python list object.
 */
void print_python_list_info(PyObject *p)
{
	Py_ssize_t size = PyList_Size(p);
	Py_ssize_t alloc = ((PyListObject *)p)->allocated;
	Py_ssize_t i;
	PyObject *item;
	const char *typeName;

	printf("[*] Size of the Python List = %zd\n", size);
	printf("[*] Allocated = %zd\n", alloc);

	for (i = 0; i < size; i++)
	{
	item = PyList_GetItem(p, i);
	typeName = Py_TYPE(item)->tp_name;

	printf("Element %zd: %s\n", i, typeName);
	}
}
