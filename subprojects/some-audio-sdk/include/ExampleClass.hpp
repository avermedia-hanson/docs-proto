#ifndef EXAMPLECLASS_HPP
#define EXAMPLECLASS_HPP

namespace example {

/** @brief An example class */
class ExampleClass {
public:
    ExampleClass() = default;
    ~ExampleClass() = default;

    /**
     * @brief An example method of `ExampleClass`
     * @details The detailed description of the method that actually says nothing.
     * @param[in] input The input array.
     * @param[out] output The output array.
     * @param[in] length The length of the input and output arrays.
     * @return The status code.
     * @retval 0 The operation is successful.
     * @retval -1 Somehow the operation is failed.
     * @throw std::invalid_argument If the input array is not valid.
     * @note This is a note.
     */
    int exampleMethod(const float *input, float *output, int length);
};

} /* namespace example */

#endif /* EXAMPLECLASS_HPP */
