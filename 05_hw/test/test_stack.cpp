#include <gtest/gtest.h>
#include <sstream>
#include <iostream>
#include "stack_fixture.h" // Подключаем StackFixture

// Тест для проверки корректности добавления элементов в стек
TEST_F(StackFixture, TestPush)
{
	push(&stack, 1); // Добавляем элемент в стек
	push(&stack, 2); // Добавляем еще один элемент

	// Проверяем, что первый элемент в стеке - 2
	EXPECT_EQ(stack.top->data, 2);
	// Проверяем, что второй элемент в стеке - 1
	EXPECT_EQ(stack.top->next->data, 1);
}

// Тест для проверки корректности удаления элемента из стека
TEST_F(StackFixture, TestPop)
{
	push(&stack, 1); // Добавляем элемент в стек
	push(&stack, 2); // Добавляем еще один элемент
	pop(&stack);	 // Удаляем верхний элемент

	// Проверяем, что после удаления верхнего элемента стек имеет значение 1
	EXPECT_EQ(stack.top->data, 1);
	// Проверяем, что следующий элемент в стеке равен nullptr (пусто)
	EXPECT_EQ(stack.top->next, nullptr);
}

// Тест для проверки правильности получения верхнего элемента стека
TEST_F(StackFixture, TestGetTop)
{
	push(&stack, 1); // Добавляем элемент в стек
	push(&stack, 2); // Добавляем еще один элемент

	// Проверяем, что верхний элемент стека - это 2
	EXPECT_EQ(getTop(&stack)->data, 2);
}

// Тест для проверки последовательности операций push и pop
TEST_F(StackFixture, TestPushPop)
{
	push(&stack, 1); // Добавляем элемент в стек
	pop(&stack);	 // Удаляем элемент из стека

	// Проверяем, что после удаления элемента стек пустой
	EXPECT_TRUE(isEmpty(&stack));
}

// Тест для проверки поиска элемента по значению в стеке
TEST_F(StackFixture, TestSearchByValue)
{
	push(&stack, 1);  // Добавляем элемент в стек
	push(&stack, -2); // Добавляем еще один элемент
	push(&stack, 3);  // Добавляем еще один элемент

	// Ищем элемент -2 в стеке
	Node *current_found = searchByValue(&stack, -2);
	// Ищем элемент 4, которого нет в стеке
	Node *current_not_found = searchByValue(&stack, 4);

	// Проверяем, что элемент -2 найден и это второй элемент в стеке
	EXPECT_EQ(current_found, stack.top->next);
	// Проверяем, что элемент 4 не найден (возвращается nullptr)
	EXPECT_EQ(current_not_found, nullptr);
}

// Тест для проверки поиска элемента по индексу в стеке
TEST_F(StackFixture, TestSearchByIndex)
{
	push(&stack, 1);  // Добавляем элемент в стек
	push(&stack, -2); // Добавляем еще один элемент
	push(&stack, 3);  // Добавляем еще один элемент

	// Ищем элемент по индексу 1
	Node *current_found = searchByIndex(&stack, 1);
	// Ищем элемент по индексу 3, который выходит за пределы стека
	Node *current_not_found = searchByIndex(&stack, 3);

	// Проверяем, что элемент с индексом 1 найден (это второй элемент в стеке)
	EXPECT_EQ(current_found, stack.top->next);
	// Проверяем, что элемент с индексом 3 не найден (возвращается nullptr)
	EXPECT_EQ(current_not_found, nullptr);
}

// Тест для проверки корректности вывода всех элементов стека
TEST_F(StackFixture, TestTraverseStack)
{
	testing::internal::CaptureStdout(); // Перехватываем стандартный вывод

	push(&stack, 1); // Добавляем элементы в стек
	push(&stack, -2);
	push(&stack, 3);
	push(&stack, -4);
	push(&stack, 0);

	// Печатаем элементы стека
	traverseStack(&stack);

	// Ожидаемый результат
	std::string expected = "Stack elements: 0 -4 3 -2 1 \n";
	std::string output = testing::internal::GetCapturedStdout(); // Получаем перехваченный вывод

	// Проверяем, что вывод совпадает с ожидаемым
	EXPECT_EQ(expected, output);
}
