#ifndef STACK_FIXTURE_H
#define STACK_FIXTURE_H

#include <gtest/gtest.h>  // Для работы с Google Test
#include "../src/stack.h" // Подключаем заголовочный файл стека

// Класс для создания тестового фикстуры для стека
class StackFixture : public ::testing::Test
{
protected:
    Stack stack; // Экземпляр стека

    // Конструктор инициализирует стек перед каждым тестом
    StackFixture()
    {
        initStack(&stack); // Инициализация стека
    }

    // Деструктор уничтожает стек после выполнения теста
    ~StackFixture() override
    {
        destroyStack(&stack); // Уничтожение стека
    }
};

#endif
