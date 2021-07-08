#include <iostream>
#include <cmath>

struct Vector {
    double x = 0;
    double y = 0;
};

Vector assignVector(Vector &vec) {

    std::cin >> vec.x;
    std::cin >> vec.y;

    return vec;
}

Vector add_vec(Vector &vec1, Vector &vec2, Vector &result) {

    result.x = vec1.x + vec2.x;
    result.y = vec1.y + vec2.y;

    return result;
}

Vector subtract_vec(Vector &vec1, Vector &vec2, Vector &result) {

    result.x = vec1.x - vec2.x;
    result.y = vec1.y - vec2.y;

    return result;
}
Vector scale_vec(Vector &vec, double scalar, Vector &result) {

    result.x = vec.x * scalar;
    result.y = vec.y * scalar;

    return result;
}

double length_vec(Vector &vec) {
    return (std::sqrt(std::pow(vec.x, 2) + std::pow(vec.y, 2)));
}

Vector normalize_vec(Vector &vec, Vector &result) {

    double lengthVec = length_vec(vec);
    result.x = vec.x / lengthVec;
    result.y = vec.y / lengthVec;

    return result;
}

int main() {

    const int var = 5;
    const std::string action[var] = {"add","subtract","scale","length","normalize"};

    std::cout << "Enter action on vectors:" << std::endl;
    std::cout << "'add' for addition vectors;" << std::endl;
    std::cout << "'subtract' for subtraction vectors;" << std::endl;
    std::cout << "'scale' for multiplying a vector by a scalar;" << std::endl;
    std::cout << "'length' for find vector length;" << std::endl;
    std::cout << "'normalize' for normalize vector." << std::endl << std::endl;
    std::cout << "Your request:";

    std::string answer;
    bool find = false;

    do {
        std::cin >> answer;
        for (int i=0;i < var;++i) {
            if (answer == action[i]) {
                find = true;
                break;
            }
        }
        if (find == false) std::cout << "Incorrect action.Repeat:";
    } while (!find);

    if (answer == "add") {
        std::cout << "Input first vector coordinates X, Y:";
        Vector vec_1 = assignVector(vec_1);
        std::cout << "Input second vector coordinates X, Y:";
        Vector vec_2 = assignVector(vec_2);

        Vector result = add_vec(vec_1, vec_2, result);
        std::cout << "Vec1(" << vec_1.x << "," << vec_1.y << ") + Vec2(" << vec_2.x << "," << vec_2.y << ")";
        std::cout << " = Vec.result(" << result.x << "," << result.y << ")" << std::endl;
    }
    if (answer == "subtract") {
        std::cout << "Input first vector coordinates X, Y:";
        Vector vec_1 = assignVector(vec_1);
        std::cout << "Input second vector coordinates X, Y:";
        Vector vec_2 = assignVector(vec_2);

        Vector result = subtract_vec(vec_1, vec_2, result);
        std::cout << "Vec1(" << vec_1.x << "," << vec_1.y << ") - Vec2(" << vec_2.x << "," << vec_2.y << ")";
        std::cout << " = Vec.result(" << result.x << "," << result.y << ")" << std::endl;
    }
    if (answer == "scale") {
        std::cout << "Input vector coordinates X, Y:";
        Vector vec = assignVector(vec);
        std::cout << "Input scalar:";
        double scalar;
        std::cin >> scalar;

        Vector result = scale_vec(vec, scalar, result);
        std::cout << "Vec(" << vec.x << "," << vec.y << ") * " << scalar;
        std::cout << " = Vec.result(" << result.x << "," << result.y << ")" << std::endl;
    }
    if (answer == "length") {
        std::cout << "Input vector coordinates X, Y:";
        Vector vec = assignVector(vec);

        double lengthVec = length_vec(vec);
        std::cout << "The vector length is: " << lengthVec << std::endl;
    }
    if (answer == "normalize") {
        std::cout << "Input vector coordinates X, Y:";
        Vector vec = assignVector(vec);

        Vector result = normalize_vec(vec, result);
        std::cout << "Result: normalize vector (" << result.x << "," << result.y << ")" << std::endl;
    }

    return 0;
}
