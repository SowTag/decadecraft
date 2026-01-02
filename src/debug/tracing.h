//
// Created by maddock on 1/2/26.
//

#ifndef DECADECRAFT_TRACING_H
#define DECADECRAFT_TRACING_H
#include <chrono>
#include <iostream>


class FunctionTracer {
public:
    explicit FunctionTracer(const char* func_name)
        : functionName(func_name), startTime(std::chrono::high_resolution_clock::now()) {
        std::cout << "Entering " << functionName << std::endl;
    }

    ~FunctionTracer() {
        const auto end_time = std::chrono::high_resolution_clock::now();
        const auto duration_us = std::chrono::duration_cast<std::chrono::microseconds>(end_time - startTime);
        long long count = duration_us.count();

        std::string unit;
        double value;

        if (count < 1000) {
            value = static_cast<double>(count);
            unit = "us";
        } else if (count < 1000000) { // Less than 1 second
            value = static_cast<double>(count) / 1000.0;
            unit = "ms";
        } else { // 1 second or more
            value = static_cast<double>(count) / 1000000.0;
            unit = "s";
        }

        std::cout << "Exiting " << functionName << " (took " << std::fixed << std::setprecision(3) << value << " " << unit << ")" << std::endl;
    }
private:
    const char* functionName;
    std::chrono::time_point<std::chrono::high_resolution_clock> startTime;
};

#define TRACE_FUNCTION() FunctionTracer tracer_##__LINE__(__func__)

#endif //DECADECRAFT_TRACING_H