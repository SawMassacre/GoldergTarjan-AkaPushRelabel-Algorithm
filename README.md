## Golderg-Tarjan's algorithm (also known as push-relabel algorithm)
- Герасимов Евгений Александрович.
- Вуз  - Двфу.
- Направление - Б9121-09.03.03пикд.
- Год - 2022.
- Алгоритм - Гольдберга-Тарьяна, поиск максимального потока в сети.

----------------------------------------------------------

## Глоссарий 

- __`Вершина`__ - в графе есть некоторое количество объектов из которых он состоит, такие объекты принято называть графом.

- __`Ребро`__ - пара упорядоченных вершин вида (vu), где v - начальная вершина ребра, а u - конечная.

- __`Ориентированный граф`__ - граф в котором ребра имеют направления.

- __`Исток/сток`__ - у графа есть две выделенные вершины, исток (S) и сток (T). Исток имеет только исходящие ребра, сток имеет только входящие. 

- __`Смежность`__ - две вершины ребра вида uv являются смежными. Смежными ребрами будем называть два ребра, имещие общую вершину, которая является u для одного из ребер, и соответственно v для другого. 

- __`Жидкость`__ - из истока в сток продвигается некоторое количество определенных элементов, проходя по ребрам графа. Для удобства будем называть эти условные элементы “жидкостью”.  Жидкостью может быть что угодно: вода в канализационной системе или пропускная способность компьютерной сети.

- __`Поток `__ - количество жидкости вытекающее из истока.Пусть F = ∑fsv (суммарное количество жидкости, вытекающее из S)  = ∑fvt (суммарное количество жидкости, втекающее в T), где f – поток, vt и sv – ребра, входящие в сток и ребра, выходящие из истока. Обозначим также поток по ребру как fuv а максимальную пропускную способность как cuv, где uv – ребро графа (дополняя, обратным данному ребру будет ребро vu). Поток по ребру определен как: fuv.

- __`Максимальный поток/пропускная способность/проходимость`__ - максимальное количество жидкости которое может пропустить ребро. Максимальный поток определен как: cuv.

- __`Насыщенное ребро`__ - ребро которое достигло своей максимальной пропускной способности. fuv = cuv.

- __`Блокирующий поток`__ - поток, который "насыщает ребро". Можно определить как: fuv + f' = cuv, где f' величина на которую нужно увеличить поток.

- __`Разрез`__ - множество ребер, удаление которых приведет к тому, что путь из истока в сток пропадет, назовем C. Величина разреза равна суммарной стоимости удаленных ребер. Логически следует что максимальный поток равен минимальному C. 

- __`Обратное ребро`__ - поток ребра равный отрицательному потоку исходного ребра, fuv = -fvu. 

- __`Остаточная сеть`__ - c'uv = cuv - fuv. Остаточная сеть дает понять на сколько еще можно увеличить поток вдоль ребра.

- __`Слоистая сеть`__ - сеть,  в которой определяются длины кратчайших путей из истока до всех остальных вершин, в слоистую сеть включаются все ребра исходной сети, которые ведут на более глубокий уровень, проверяется это инкрементацией индекса глубины. В слоистой сети, конечном виде, каждый путь является кратчайшим. В такой сети алгоритм тратит n на путь. Ребер m значит и путей m. Слоистая сеть нужна для сортировке по глубине.

- __`Переполненная вершина`__ - данное определение имеет смысл только при рассмотрении непосредстенно реализации алгоритма. Суть заключается в том, что вершина ребра не может хранить в себе жидкость, или принимать и выдавать больше жидкости чем в нее поступает. Убедиться в верности потока можно взяв вершину и убедившись в том, что попавшее в нее количество жидкости равняется вышедшему, это дает понять, что в вершине не задерживается и не появляется новая жидкость (данные, вода и другие ресурсы). Жидкость из переполненной вершины надо проталкивать в смежные.

----------------------------------------------------------

## Суть алгоритма

*** Алгоритм Гольдберга-Тарьяна *** - алгоритм решающий задачу нахождения максимального потока в сети, работающий за O(V²E) (есть модификации работющие и за меньшее время)

----------------------------------------------------------

## Модель ситуации

Дан ориентированный граф, ребра которого имеют 