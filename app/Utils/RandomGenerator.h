#ifndef RandomGenerator_H
#define RandomGenerator_H

#include <random>

template <typename T>
class RandomGenerator {
   private:
    static std::mt19937 generator;
    static std::uniform_real_distribution<double> distribution;
    RandomGenerator();

   public:
    template <typename U>
    static T Generate(U min, U max) {
        distribution.param(std::uniform_real_distribution<double>::param_type(min, max));
        return distribution(generator);
    }
};

template <typename T>
std::mt19937 RandomGenerator<T>::generator{std::random_device()()};

template <typename T>
std::uniform_real_distribution<double> RandomGenerator<T>::distribution{};

#endif  // !RandomGenerator_H