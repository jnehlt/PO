#include "stack.hpp"

int main(void)
{
	Stack stack;
	stack.init(stack);

	stack.push(stack, 7);
	stack.push(stack, 18);
	stack.push(stack, 12);
	stack.push(stack, 593);
	stack.push(stack, 78);

	stack.isEmpty(stack) ? cout << "EMPTY!\n" : cout << "NOT EMPTY!\n";

	stack.push(stack, 118);
	stack.push(stack, 312);
	stack.push(stack, 53);
	stack.push(stack, 1227);
	stack.push(stack, 1885);
	stack.push(stack, 1221);
	stack.push(stack, 5853);
	stack.push(stack, 76);
	stack.push(stack, 28);
	stack.push(stack, 3121);
	stack.push(stack, 536);


	cout << stack.pop(stack) << endl;
	cout << stack.pop(stack) << endl;
	cout << stack.pop(stack) << endl;
	cout << stack.pop(stack) << endl;
	cout << stack.pop(stack) << endl;
	cout << stack.pop(stack) << endl;
	cout << stack.pop(stack) << endl;
	cout << stack.pop(stack) << endl;
	cout << stack.pop(stack) << endl;

	stack.clear(stack);

	stack.destroy(stack);

	return 0;
}