int runTests(int testNum) {
    int c;
    vector <int> ans = {5, 6, 15, 14, 120};
    c = testNum;
    string message = "correct!";
    int V, s, t, receivedAns;
    switch (c) {
        case 0: {
            V = 6;
            Graph g(V);
            s = 0, t = 5;
            g.addEdge(0, 1, 3);
            g.addEdge(0, 2, 3);
            g.addEdge(1, 2, 2);
            g.addEdge(1, 3, 3);
            g.addEdge(2, 4, 2);
            g.addEdge(3, 4, 4);
            g.addEdge(3, 5, 2);
            g.addEdge(4, 5, 3);
            receivedAns = g.getMaxFlow(s, t);
            if (ans[c] == receivedAns)
                message = "correct!";
            else
                message = "incorrect!";
            cout << "expected answer: " << ans[c] << " received answer: "
                 << receivedAns << " " << message << "\n";
            g.refresh();
            break;
        }
        case 1: {
            V = 7;
            Graph g(V);
            s = 0, t = 6;
            g.addEdge(0, 1, 3);
            g.addEdge(0, 2, 15);
            g.addEdge(1, 3, 8);
            g.addEdge(3, 2, 9);
            g.addEdge(3, 4, 8);
            g.addEdge(2, 4, 11);
            g.addEdge(4, 5, 3);
            g.addEdge(5, 6, 7);
            g.addEdge(3, 6, 10);
            receivedAns = g.getMaxFlow(s, t);
            if (ans[c] == receivedAns)
                message = "correct!";
            else
                message = "incorrect!";
            cout << "expected answer: " << ans[c] << " received answer: "
                 << receivedAns << " " << message << "\n";
            g.refresh();
            break;
        }
        case 2: {
            V = 4;
            Graph g(V);
            s = 0, t = 3;
            g.addEdge(0, 1, 10);
            g.addEdge(0, 2, 5);
            g.addEdge(1, 2, 15);
            g.addEdge(1, 3, 5);
            g.addEdge(2, 3, 10);
            receivedAns = g.getMaxFlow(s, t);
            if (ans[c] == receivedAns)
                message = "correct!";
            else
                message = "incorrect!";
            cout << "expected answer: " << ans[c] << " received answer: "
                 << receivedAns << " " << message << "\n";
            g.refresh();
            break;
        }
        case 3: {
            V = 7;
            Graph g(V);
            s = 0, t = 6;
            g.addEdge(0, 1, 4);
            g.addEdge(0, 2, 6);
            g.addEdge(0, 3, 5);
            g.addEdge(1, 2, 1);
            g.addEdge(2, 1, 1);
            g.addEdge(2, 3, 2);
            g.addEdge(3, 2, 2);
            g.addEdge(3, 5, 5);
            g.addEdge(2, 5, 4);
            g.addEdge(2, 4, 5);
            g.addEdge(1, 4, 7);
            g.addEdge(4, 5, 1);
            g.addEdge(5, 4, 1);
            g.addEdge(4, 6, 6);
            g.addEdge(5, 6, 8);
            receivedAns = g.getMaxFlow(s, t);
            if (ans[c] == receivedAns)
                message = "correct!";
            else
                message = "incorrect!";
            cout << "expected answer: " << ans[c] << " received answer: "
                 << receivedAns << " " << message << "\n";
            g.refresh();
            break;
        }
        case 4: {
            V = 6;
            Graph g(V);
            s = 0, t = 5;
            g.addEdge(0, 1, 90);
            g.addEdge(0, 3, 110);
            g.addEdge(1, 2, 60);
            g.addEdge(3, 1, 10);
            g.addEdge(1, 4, 30);
            g.addEdge(3, 4, 30);
            g.addEdge(2, 4, 40);
            g.addEdge(2, 5, 50);
            g.addEdge(4, 5, 100);
            receivedAns = g.getMaxFlow(s, t);
            if (ans[c] == receivedAns)
                message = "correct!";
            else
                message = "incorrect!";
            cout << "expected answer: " << ans[c] << " received answer: "
                 << receivedAns << " " << message << "\n";
            g.refresh();
            break;
        }
    }
}