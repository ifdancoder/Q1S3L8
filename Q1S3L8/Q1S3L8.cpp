#include <iostream>
#include <vector>
#include <gtest/gtest.h>
#include "StudentsGroup.h"

using namespace std;

TEST(GetStudentInfo, GetAverageScore) {
    StudentsGroup sg;
    vector<int> evals1{ 4, 4, 5, 4, 4 };
    sg.addStudent(evals1, "Daniil", "Ivanov");
    ASSERT_EQ(4.2, sg.GetAverageScore(*sg.genFN("Daniil", "Ivanov")));
}

int main()
{
    /*{
        StudentsGroup sg;

        vector<int> evals1{ 4, 4, 5, 4, 4 };
        sg.addStudent(evals1, "Daniil", "Ivanov");

        vector<int> evals2{ 4, 5, 5, 5, 4 };
        sg.addStudent(evals2, "Andre", "Maltuguev", "Alexeevich");

        sg.Save();
    }

    {
        StudentsGroup sg;
        sg.Open();
        cout << sg.GetAllInfo() << "===\n";
        cout << "Daniil's average: " << sg.GetAverageScore(*sg.genFN("Daniil", "Ivanov")) << endl << endl;
        cout << "Daniil's info:\n\n" << sg.GetAllInfo(*sg.genFN("Daniil", "Ivanov"));
    }*/

    {
        testing::InitGoogleTest();
        return RUN_ALL_TESTS();
    }
    return 0;
}