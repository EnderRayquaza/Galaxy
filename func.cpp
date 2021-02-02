#include "func.h"

int random(int a, int b)
{
    std::random_device rd;
    std::default_random_engine eng(rd());
    std::uniform_int_distribution<int> disr(a, b);
    int r(disr(eng));
    return r;
}

int fake_random(int a, int b)
{
    int r = a + rand()%b;
    return r;
}

double average(std::vector<double> vec)
{
    double Σ(0);
    for (int i(0); i < vec.size(); i++)
        Σ += vec[i];
    Σ /= vec.size();
    return Σ;
}

double averageWithoutIndex(std::vector<double> vec, int index)
{
    if (index > vec.size())
    {
        std::cout << "Index too big !" << std::endl;
        return 1;
    }
    if (vec.size() <= 1)
    {
        return 1;
    }
    double Σ(0);
    for (int i(0); i < vec.size(); i++)
        if(i != index)
            Σ += vec[i];
    Σ /= vec.size()-1;
    std::cout << "Σ : " << Σ << std::endl;
    return Σ;
}