#ifndef STATISTICS_H
#define STATISTICS_H
//5)
template <typename T, typename U, typename V, typename W, typename X>
class Statistics {
private:
    T mean;
    U median;
    V mode;
    W variance;
    X standardDeviation;

public:
    // Конструктори та методи
    Statistics(T m, U md, V mo, W v, X sd)
        : mean(m), median(md), mode(mo), variance(v), standardDeviation(sd) {}

    void display() const {
        std::cout << "Mean: " << mean << ", Median: " << median << ", Mode: " << mode
            << ", Variance: " << variance << ", StdDev: " << standardDeviation << std::endl;
    }
};
#endif

