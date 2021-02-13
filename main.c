#include <stdio.h>
#include "numerical/matrix.h"
#include "util/printer.h"
#include "preprocessing/load.h"
#include "preprocessing/split.h"
#include <stdlib.h>

int main() {

    Iris IrisDataset = load_iris("../dataset/Iris.csv");
    Matrix X = IrisDataset.X;
    Matrix y = IrisDataset.y;

    TrainTestSplit tts = split_train_test(X, y, 0.2F);

    Matrix TrainX = tts.TrainX;
    Matrix TestX = tts.TestX;

    print_matrix(TrainX);
    print_matrix(TestX);


//    double a[][2] = {{1, 2}, {3, 4}, {5, 6}, {7, 8}};
//    Matrix A = create_matrix(4, 2, *a);
//    print_matrix(A);
//
//    shuffle(A);
//    print_matrix(A);

    return 0;
}
