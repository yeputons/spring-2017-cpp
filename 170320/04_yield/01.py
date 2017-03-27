#!/usr/bin/env python3

# Пример корутин к одному из проектов по C++.

def foo():
   print("a1")
   yield 1  # "Приостанавливает" выполнение функции. Получаем функцию-генератор, которая генерирует элементы по очереди.
   print("a2")
   yield 2
   print("a3")
   yield 3
   print("a4")


def bar():
   while True:
       yield 1


n = foo()
print(next(n))
print(next(n))
print(next(n))
print(next(n))
