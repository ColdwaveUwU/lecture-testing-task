#include <gtest/gtest.h>
#include "../src/stack.h"
#include "stack_fixture.h" // Подключаем StackFixture

// Тест для проверки, что стек пустой после инициализации
TEST_F(StackFixture, TestStackInitialization)
{
	// Проверяем, что стек пустой после инициализации
	EXPECT_TRUE(isEmpty(&stack)) << "Stack should be empty after initialization";
}

// Тест для проверки добавления элемента в стек
TEST_F(StackFixture, TestPushElement)
{
	push(&stack, 10); // Добавляем элемент в стек

	// Проверяем, что стек не пустой после добавления элемента
	EXPECT_FALSE(isEmpty(&stack)) << "Stack should not be empty after pushing an element";
}

// Тест для проверки удаления элемента из стека
TEST_F(StackFixture, TestPopElement)
{
	push(&stack, 10); // Добавляем элемент в стек
	pop(&stack);	  // Удаляем элемент из стека

	// Проверяем, что стек пустой после удаления единственного элемента
	EXPECT_TRUE(isEmpty(&stack)) << "Stack should be empty after popping the only element";
}

// Тест для проверки нескольких операций push/pop
TEST_F(StackFixture, TestMultiplePushPop)
{
	// Добавляем несколько элементов в стек
	push(&stack, 10);
	push(&stack, 20);
	push(&stack, 30);

	// Проверяем, что стек не пустой после добавления элементов
	EXPECT_FALSE(isEmpty(&stack)) << "Stack should not be empty after pushing multiple elements";

	// Удаляем два элемента из стека
	pop(&stack);
	pop(&stack);

	// Проверяем, что стек не пустой после удаления двух элементов
	EXPECT_FALSE(isEmpty(&stack)) << "Stack should not be empty after popping two elements";

	// Удаляем последний элемент
	pop(&stack);

	// Проверяем, что стек пустой после удаления всех элементов
	EXPECT_TRUE(isEmpty(&stack)) << "Stack should be empty after popping all elements";
}
