#include <limits>
#include <stdexcept>
#include <cmath>

namespace Safe
{
    //-----------------------------------------------------------------------------------------------------//
    //                                           Signed Integrals
    //-----------------------------------------------------------------------------------------------------//

    template <typename T>
    typename std::enable_if <std::is_signed <T>::value && std::is_integral <T>::value, T>::type Add(T a, T b)
    {
        if (b > 0 && a > std::numeric_limits <T>::max() - b)
            throw std::overflow_error("Overflow");

        if (b < 0 && a < std::numeric_limits <T>::min() - b)
            throw std::overflow_error("Underflow");

        return a + b;
    }

    template <typename T>
    typename std::enable_if <std::is_signed <T>::value && std::is_integral <T>::value, T>::type Subtract(T a, T b)
    {
        if (b > 0 && a < std::numeric_limits <T>::min() + b)
            throw std::overflow_error("Underflow");

        if (b < 0 && a > std::numeric_limits <T>::max() + b)
            throw std::overflow_error("Overflow");

        return a - b;
    }

    template <typename T>
    typename std::enable_if <std::is_signed <T>::value && std::is_integral <T>::value, T>::type Multiply(T a, T b)
    {
        if (a > 0 && b > 0 && a > std::numeric_limits <T>::max() / b)
            throw std::overflow_error("Overflow");

        if (a > 0 && b < 0 && b < std::numeric_limits <T>::min() / a)
            throw std::overflow_error("Underflow");

        if (a < 0 && b > 0 && a < std::numeric_limits <T>::min() / b)
            throw std::overflow_error("Underflow");

        if (a < 0 && b < 0 && b < std::numeric_limits <T>::max() / a)
            throw std::overflow_error("Overflow");

        return a * b;
    }

    template <typename T>
    typename std::enable_if <std::is_signed <T>::value && std::is_integral <T>::value, T>::type Divide(T a, T b)
    {
        if (b == 0)
            throw std::overflow_error("Division by zero");

        if (a == std::numeric_limits <T>::min() && b == -1)
            throw std::overflow_error("Overflow");

        return a / b;
    }

    //-----------------------------------------------------------------------------------------------------//
    //                                         Unsigned Integrals
    //-----------------------------------------------------------------------------------------------------//

    template <typename T>
    typename std::enable_if <std::is_unsigned <T>::value && std::is_integral <T>::value, T>::type Add(T a, T b)
    {
        if (a > std::numeric_limits <T>::max() - b)
            throw std::overflow_error("Overflow");

        return a + b;
    }

    template <typename T>
    typename std::enable_if <std::is_unsigned <T>::value && std::is_integral <T>::value, T>::type Subtract(T a, T b)
    {
        if (a < std::numeric_limits <T>::min() + b)
            throw std::overflow_error("Underflow");

        return a - b;
    }

    template <typename T>
    typename std::enable_if <std::is_unsigned <T>::value && std::is_integral <T>::value, T>::type Multiply(T a, T b)
    {
        if (b != 0 && a > std::numeric_limits <T>::max() / b)
            throw std::overflow_error("Overflow");

        return a * b;
    }

    template <typename T>
    typename std::enable_if <std::is_unsigned <T>::value && std::is_integral <T>::value, T>::type Divide(T a, T b)
    {
        if (b == 0)
            throw std::overflow_error("Division by zero");

        return a / b;
    }

    //-----------------------------------------------------------------------------------------------------//
    //                                           Floating-Points
    //-----------------------------------------------------------------------------------------------------//

    template <typename T>
    typename std::enable_if <std::is_floating_point <T>::value, T>::type Add(T a, T b)
    {
        T result = a + b;

        if (!std::isfinite(result))
            throw std::overflow_error("Non-finite number");

        return result;
    }

    template <typename T>
    typename std::enable_if <std::is_floating_point <T>::value, T>::type Subtract(T a, T b)
    {
        T result = a - b;

        if (!std::isfinite(result))
            throw std::overflow_error("Non-finite number");

        return result;
    }

    template <typename T>
    typename std::enable_if <std::is_floating_point <T>::value, T>::type Multiply(T a, T b)
    {
        T result = a * b;

        if (!std::isfinite(result))
            throw std::overflow_error("Non-finite number");

        return result;
    }

    template <typename T>
    typename std::enable_if <std::is_floating_point <T>::value, T>::type Divide(T a, T b)
    {
        T result = a / b;

        if (!std::isfinite(result))
            throw std::overflow_error("Non-finite number");

        return result;
    }
}
