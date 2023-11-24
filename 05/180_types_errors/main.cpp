int area(int inputLength, int inputWidth) {
    return inputLength * inputWidth;
}

int main() {
    int x0 = arena(7);
    int x1 = area(7);
    int x2 = area("seven", 2);
    int x3 = area(8, 9, 10);
    int x4 = area("ein", "zwei");
    int x5 = area("2, 3");
    int x6 = area(&7, &8);
}
