\# Отчет по лабораторной работе №1

\## Задача коммивояжера: точный и эвристический алгоритмы



\### Описание

В работе реализованы:

1\. \*\*Точный алгоритм\*\* — полный перебор перестановок городов с нахождением наилучшего и наихудшего маршрутов.

2\. \*\*Эвристический алгоритм\*\* — метод ближайшего соседа (Nearest Neighbor).



Эксперименты проведены для размерностей N = 4, 6, 8, 10 (по 3 запуска для каждой).  

Протестированы два диапазона стоимостей: базовый и большой разброс.



\---



\### Результаты работы программы



\#### 1. Базовый диапазон стоимостей (до 100)

```text

Testing 4 cities

Run #1:

&#x20; Exact: best = 182, worst = 275, time = 2181 mcs

&#x20; NN:    cost = 222, time = 10 mcs

&#x20; Quality: 56.9892%

Run #2:

&#x20; Exact: best = 190, worst = 289, time = 5 mcs

&#x20; NN:    cost = 252, time = 1 mcs

&#x20; Quality: 37.3737%

Run #3:

&#x20; Exact: best = 190, worst = 309, time = 5 mcs

&#x20; NN:    cost = 190, time = 1 mcs

&#x20; Quality: 100%



Testing 6 cities

Run #1:

&#x20; Exact: best = 117, worst = 430, time = 35 mcs

&#x20; NN:    cost = 117, time = 1 mcs

&#x20; Quality: 100%

Run #2:

&#x20; Exact: best = 190, worst = 429, time = 31 mcs

&#x20; NN:    cost = 214, time = 1 mcs

&#x20; Quality: 89.9582%

Run #3:

&#x20; Exact: best = 236, worst = 487, time = 34 mcs

&#x20; NN:    cost = 285, time = 1 mcs

&#x20; Quality: 80.4781%



Testing 8 cities

Run #1:

&#x20; Exact: best = 213, worst = 654, time = 1298 mcs

&#x20; NN:    cost = 236, time = 3 mcs

&#x20; Quality: 94.7846%

Run #2:

&#x20; Exact: best = 230, worst = 671, time = 1492 mcs

&#x20; NN:    cost = 230, time = 6 mcs

&#x20; Quality: 100%

Run #3:

&#x20; Exact: best = 271, worst = 677, time = 1331 mcs

&#x20; NN:    cost = 389, time = 3 mcs

&#x20; Quality: 70.936%



Testing 10 cities

Run #1:

&#x20; Exact: best = 225, worst = 845, time = 97667 mcs

&#x20; NN:    cost = 397, time = 6 mcs

&#x20; Quality: 72.2581%

Run #2:

&#x20; Exact: best = 246, worst = 872, time = 127828 mcs

&#x20; NN:    cost = 284, time = 5 mcs

&#x20; Quality: 93.9297%

Run #3:

&#x20; Exact: best = 261, worst = 823, time = 122300 mcs

&#x20; NN:    cost = 309, time = 5 mcs

&#x20; Quality: 91.4591%

```



\#### 2. Большой диапазон стоимостей (до 10 000)

```text

Testing 4 cities

Run #1:

&#x20; Exact: best = 7414, worst = 19647, time = 19 mcs

&#x20; NN:    cost = 7414, time = 8 mcs

&#x20; Quality: 100%

Run #2:

&#x20; Exact: best = 10530, worst = 23802, time = 5 mcs

&#x20; NN:    cost = 10530, time = 1 mcs

&#x20; Quality: 100%

Run #3:

&#x20; Exact: best = 7734, worst = 25032, time = 5 mcs

&#x20; NN:    cost = 7734, time = 1 mcs

&#x20; Quality: 100%



Testing 6 cities

Run #1:

&#x20; Exact: best = 9456, worst = 42214, time = 38 mcs

&#x20; NN:    cost = 15306, time = 2 mcs

&#x20; Quality: 82.1418%

Run #2:

&#x20; Exact: best = 9542, worst = 40212, time = 36 mcs

&#x20; NN:    cost = 13153, time = 2 mcs

&#x20; Quality: 88.2263%

Run #3:

&#x20; Exact: best = 18036, worst = 38980, time = 28 mcs

&#x20; NN:    cost = 27105, time = 2 mcs

&#x20; Quality: 56.6988%



Testing 8 cities

Run #1:

&#x20; Exact: best = 17312, worst = 69428, time = 1252 mcs

&#x20; NN:    cost = 26411, time = 3 mcs

&#x20; Quality: 82.5409%

Run #2:

&#x20; Exact: best = 12030, worst = 64560, time = 867 mcs

&#x20; NN:    cost = 12648, time = 4 mcs

&#x20; Quality: 98.8235%

Run #3:

&#x20; Exact: best = 17598, worst = 63319, time = 746 mcs

&#x20; NN:    cost = 30493, time = 2 mcs

&#x20; Quality: 71.7963%



Testing 10 cities

Run #1:

&#x20; Exact: best = 16444, worst = 89691, time = 92000 mcs

&#x20; NN:    cost = 16637, time = 5 mcs

&#x20; Quality: 99.7365%

Run #2:

&#x20; Exact: best = 14506, worst = 87806, time = 113214 mcs

&#x20; NN:    cost = 19728, time = 5 mcs

&#x20; Quality: 92.8759%

Run #3:

&#x20; Exact: best = 13931, worst = 74955, time = 334083 mcs

&#x20; NN:    cost = 17137, time = 5 mcs

&#x20; Quality: 94.7463%

```



\---



\### Выводы



1\. \*\*Рост времени работы точного алгоритма:\*\*

&#x20;  \* Количество перестановок равно \*\*(N - 1)!\*\*.

&#x20;  \* Для \*\*N = 4\*\* (3! = 6 перестановок) время составляет около 5–20 мкс.

&#x20;  \* Для \*\*N = 6\*\* (5! = 120) — около 30–40 мкс.

&#x20;  \* Для \*\*N = 8\*\* (7! = 5040) — около 1 000 мкс (1 мс).

&#x20;  \* Для \*\*N = 10\*\* (9! = 362 880) — время резко возрастает до 100 000 – 330 000 мкс (0.1–0.33 секунды).

&#x20;  \* При \*\*N = 12\*\* вариантов уже 11! ≈ 40 миллионов (займет порядка минуты), а при \*\*N = 14\*\* (13! ≈ 6.2 млрд) перебор потребует часы непрерывной работы.

&#x20;  \* \*\*Вывод:\*\* Точный расчет методом полного перебора становится практически затруднительным, начиная с \*\*12–14 городов\*\*.



2\. \*\*Эффективность эвристики (Nearest Neighbor):\*\*

&#x20;  \* Время работы эвристики на всех тестах составляет стабильные \*\*1–10 микросекунд\*\* и практически не растет с увеличением N на исследуемых размерностях.

&#x20;  \* Среднее качество решения составило \*\*\~80–90%\*\*, а в ряде случаев (особенно при малом числе городов) эвристика находит точный оптимум (100% качество).

&#x20;  \* Изменение разброса стоимостей (от десятков до тысяч) не снижает эффективность метода — алгоритм одинаково хорошо справляется как с маленькими, так и с большими числами.

