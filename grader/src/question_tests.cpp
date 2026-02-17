#include "grader.h"
#include "test_case.h"

// TEST CASES FOR EACH QUESTIONS GO HERE
std::vector<TestCase> get_question_tests(int question_number)
{
    switch (question_number)
    {
    case 1:
    {
        return {
            {"1 2 3 4 5\n", "15"},
            {"10 20 30\n", "60"},
            {"0 0 0 0\n", "0"},
            {"5\n", "5"},
            {"-1 1\n", "0"}};
    }
    case 2:
    {
        return {
            {"asasfjkjcgiasdfjsfasfscgiasdfajsakjcgiajjjjcgiasdfCgIja;scgi\n", "6"},
        };
    }
    case 3:
    {
        return {
            {"R R P P S S R P S R", "0"},
            {"R P P S S R R P S R P S", "6"},
            {"R S P R S P R P S", "-3"},
            {"R R P S S R R R P S P S S", "5"},
            {"R P P P S P R R R P P S S S", "0"},
            {"R P P S S R", "0"}};
    }
    case 4:
    {
        return {{"aaaaaaaagjjjjjgjjj", "g"},
                {"qwerdtyuiopzxcvbnmdlkj", "d"}};
    }
    case 5:
    {
        return {
            {"abcijicba", "1"},
            {"aasdfve", "0"}};
    }
    case 6:
    {
        return {};
    }
    case 7:
    {
        return {{"N[3,7,11](N[1,2](L[1])(L[1]))(L[2])", "0"}};
    }
    case 8:
    {
        return {{"441110100011110000", "1"},
                {"551110011100111001110000000000", "1"}};
    }
    case 9:
    {
        return {};
    }
    case 10:
    {
        return {};
    }
    default:
        return {};
    }
}
