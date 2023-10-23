# SmartCalculator
Оконное приложение инженерный калькулятор, разработанное на языках С и С++ с использованием структурного программирования. Имеется возможность отрисовки графиков функций с масштабированием, а также дополнительно реализован кредитный калькулятор.


## Реализация проекта

Реализована программа SmartCalc версии v1.0:

- Программа разработана на языке C стандарта C11 с использованием компилятора gcc. Я использовал некоторые дополнительные библиотеки и модули QT
- Программа может быть собрана с помощью Makefile, который содержит стандартный набор целевых объектов для GNU-программ: all, install, uninstall, clean, dvi, dist, tests, gcov_report. Каталог установки может быть произвольным, кроме строительного
- Имеется полный охват модулей , связанных с вычислением выражений с помощью модульных тестов с использованием библиотеки Check
- Реализация GUI, основанная на любой библиотеке GUI с API для C11 (Qt, OpenGL)
- В программу можно вводить как целые, так и вещественные числа с точкой.
- Расчет будет произведен после того, как вы завершите ввод вычисляющего выражения и нажмете = символ.
- Построение графика функции, заданной выражением в инфиксной записи с переменной x (с координатными осями, отметкой используемого масштаба и адаптивной сеткой)
- Домен и кодомен функции ограничены как минимум числами от -1000 до 1000
- Для построения графика функции необходимо дополнительно указать отображаемый домен и кодомен
- Проверяемая точность дробной части составляет не менее 7 знаков после запятой
- Пользователи могут вводить до 255 символов
- Арифметические выражения в инфиксной записи поддерживают следующие арифметические операции и математические функции:

    - **Арифметические опереторы**:

      | Operator name | Infix notation <br /> (Classic) | Prefix notation <br /> (Polish notation) |  Postfix notation <br /> (Reverse Polish notation) |
      | --------- | ------ | ------ | ------ |
      | Brackets | (a + b) | (+ a b) | a b + |
      | Addition | a + b | + a b | a b + |
      | Subtraction | a - b | - a b | a b - |
      | Multiplication | a * b | * a b | a b * |
      | Division | a / b | / a b | a b \ |
      | Power | a ^ b | ^ a b | a b ^ |
      | Modulus | a mod b | mod a b | a b mod |
      | Unary plus | +a | +a | a+ |
      | Unary minus | -a | -a | a- |


    - **Функции**:
  
      | Function description | Function |
      | ------ | ------ |
      | Computes cosine | cos(x) |
      | Computes sine | sin(x) |
      | Computes tangent | tan(x) |
      | Computes arc cosine | acos(x) |
      | Computes arc sine | asin(x) |
      | Computes arc tangent | atan(x) |
      | Computes square root | sqrt(x) |
      | Computes natural logarithm | ln(x) |
      | Computes common logarithm | log(x) |


## Кредитный калькулятор

Есть специальный режим "кредитный калькулятор":

- Ввод: общая сумма кредита, срок, процентная ставка, тип (аннуитетный, дифференцированный)
- Вывод: ежемесячный платеж, переплата по кредиту, общий платеж

## Результат

Ниже вы можете увидеть работу программы и пример вычислений:

![](/images/InShot_20231023_084722975.gif)

