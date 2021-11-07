//Порівняти перші символи двох рядків, якщо вони однакові, то поміняти місцями рядки,
// якщо різні - вставити менший за розміром в початок та в кінець  більшого.

#include <iostream>

using namespace std;

struct Pair {
    char *first;
    char *second;
};

int length(char *array);

void checking(int expected, int actual, char *message);

void checking(char *expected, char *actual, char *message);

void checking(Pair expected, Pair actual, char *message);

bool is_equal(char *first, char *second);

char *add(char *first, char *second);

Pair change_lines(Pair lines);
Pair change_lines_std(Pair lines);

int main() {
    checking(0, length(""), "Should return 0");
    checking(5, length("Hello"), "Word contains 5 letters");

    cout << "\n\n";

    checking(1, is_equal("Hello", "Hello"), "Lines are equal");
    checking(0, is_equal("Hello", "Hi"), "Lines are not equal");

    cout << "\n\n";

    checking("ABC", add("AB", "C"), "Should concatenate lines");

    cout << "\n\n";

    checking({"RAMA", "ROMA"}, change_lines({"ROMA", "RAMA"}),
             "Should swapping if first letters are equals ");
    checking({"ANN", "ANNURUKANN"}, change_lines({"ANN", "URUK"}),
             "Should set greatest word between less ");
    checking({"BOBFREDBOB", "BOB"}, change_lines({"FRED", "BOB"}),
             "Should set greatest word between less ");
    checking({"ANN", "ANNZOEANN"}, change_lines({"ANN", "ZOE"}),
             "Should edit second if lines` size are equal ");

    cout << "\n\n";

    checking({"RAMA", "ROMA"}, change_lines_std({"ROMA", "RAMA"}),
             "Should swapping if first letters are equals(std) ");
    checking({"ANN", "ANNURUKANN"}, change_lines_std({"ANN", "URUK"}),
             "Should set greatest word between less(std) ");
    checking({"BOBFREDBOB", "BOB"}, change_lines_std({"FRED", "BOB"}),
             "Should set greatest word between less(std) ");
    checking({"ANN", "ANNZOEANN"}, change_lines_std({"ANN", "ZOE"}),
             "Should edit second if lines` size are equal (std) ");


    return 0;
}

int length(char *array) {
    int size = 0;
    while (*(array + size) != '\0') {
        size++;
    }
    return size;
}

void checking(int expected, int actual, char *message) {
    if (expected != actual) {
        cout << " Expected: " << expected
             << " But return: " << actual
             << " With message: " << message << endl;
    } else cout << "Test with message: " << message << " comleted \n";
}

void checking(char *expected, char *actual, char *message) {
    if (!is_equal(expected, actual)) {
        cout << " Expected: " << expected
             << " But return: " << actual
             << " With message: " << message << endl;
    } else cout << "Test with message: " << message << " comleted \n";
}

void checking(Pair expected, Pair actual, char *message) {
    if (!is_equal(expected.first, actual.first) || !is_equal(expected.second, actual.second)) {
        cout << " Expected: " << expected.first << " , " << expected.second
             << " But return: " << actual.first << " , " << actual.second
             << " With message: " << message << endl;
    } else cout << "Test with message: " << message << " comleted \n";


}

bool is_equal(char *first, char *second) {
    if (length(first) != length(second)) {
        return false;
    }

    for (int i = 0; true; ++i) {
        char left_letter = *(first + i);
        char right_letter = *(second + i);

        if (left_letter == '\0' || right_letter == '\0') {
            break;
        }

        if (left_letter != right_letter) {
            return false;
        }
    }
    return true;
}

char *add(char *first, char *second) {
    int new_line_size = length(first) + length(second);
    char *new_line = new char[new_line_size + 1];
    int new_line_index = 0;

    for (int i = 0; i < length(first); ++i) {
        *(new_line + new_line_index) = *(first + i);
        new_line_index++;
    }

    for (int i = 0; i < length(second); ++i) {
        *(new_line + new_line_index) = *(second + i);
        new_line_index++;
    }

    *(new_line + new_line_size) = '\0';
    return new_line;
}

Pair change_lines(Pair lines) {
    char first_element_of_first_line = *(lines.first + 0);
    char first_element_of_second_line = *(lines.second + 0);

    if (first_element_of_first_line == first_element_of_second_line) {
        return {lines.second, lines.first};
    }

    if (length(lines.first) > length(lines.second)) {
        char *result = add(lines.second, lines.first);
        result = add(result, lines.second);
        return {result, lines.second};
    } else {
        char *result = add(lines.first, lines.second);
        result = add(result, lines.first);
        return {lines.first, result};
    }

}

Pair change_lines_std(Pair lines) {
    char first_element_of_first_line = *(lines.first + 0);
    char first_element_of_second_line = *(lines.second + 0);

    if (first_element_of_first_line == first_element_of_second_line) {
        return {lines.second, lines.first};
    }

    if (strlen(lines.first) > strlen(lines.second)) {
        char *result = new char [strlen(lines.second)+strlen(lines.first)+strlen(lines.second)+1];
        strcpy(result, lines.second );
        strcat(result, lines.first);
        strcat(result, lines.second);
        return {result, lines.second};
    } else {
        char *result = new char [strlen(lines.first)+strlen(lines.second)+strlen(lines.first)+1];
        strcpy(result, lines.first );
        strcat(result, lines.second);
        strcat(result, lines.first);
        return {lines.first, result};
    }

}