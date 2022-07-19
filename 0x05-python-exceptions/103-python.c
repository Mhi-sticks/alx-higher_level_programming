#include <stdio.h>
#include <Python.h>

/**
 * print_python_bytes - Prints bytes information
 *
 * @p: Python Object
 * Return: no return
 */
void print_python_bytes(PyObject *p)
{
	char *string;
	long int size, i, limit;

	setbuf(stdout, NULL);

	printf("[.] bytes object info\n");
	if (!PyBytes_Check(p))
	{
		printf("  [ERROR] Invalid Bytes Object\n");
		setbuf(stdout, NULL);
		return;
	}

	size = ((PyVarObject *)(p))->ob_size;
	string = ((PyBytesObject *)p)->ob_sval;

	printf("  size: %ld\n", size);
	printf("  trying string: %s\n", string);

	if (size >= 10)
		limit = 10;
	else
		limit = size + 1;

	printf("  first %ld bytes:", limit);

	for (i = 0; i < limit; i++)
		if (string[i] >= 0)
			printf(" %02x", string[i]);
		else
			printf(" %02x", 256 + string[i]);

	printf("\n");
	setbuf(stdout, NULL);
}

/**
 * print_python_float - Prints float information
 *
 * @p: Python Object
 * Return: no return
 */
void print_python_float(PyObject *p)
{
	double val;
	char *nf;

	setbuf(stdout, NULL);
	printf("[.] float object info\n");

	if (!PyFloat_Check(p))
	{
		printf("  [ERROR] Invalid Float Object\n");
		setbuf(stdout, NULL);
		return;
	}


