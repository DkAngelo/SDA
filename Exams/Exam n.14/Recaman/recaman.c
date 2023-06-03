int RecamanRec(int n) {
    int a = n - 1;
    if (a == 1) {
        return 1;
    }
    else if (RecamanRec(a) % a == 0) {
        return RecamanRec(a) / a;
    }
    else {
        return RecamanRec(a) * a;
    }
}

int Recaman(int n) {
    if (n < 1) {
        return -1;
    }
    else if (n == 1) {
        return 1;
    }
    return RecamanRec(n);
}