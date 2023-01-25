#include <random>

class RandomIntGenerator {
public:
    RandomIntGenerator() :
        m_distribution(1, 6) {}

    RandomIntGenerator(int min, int max) :
        m_distribution(min, max) {}

    int next() {
        return m_distribution(m_randomEngine);
    }

    void setRange(int min, int max) {
        m_distribution.param(std::uniform_int_distribution<>::param_type(min, max));
    }

private:
    std::mt19937 m_randomEngine{ std::random_device{}() };
    std::uniform_int_distribution<> m_distribution;
};