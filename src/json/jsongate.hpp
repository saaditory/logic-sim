#ifndef JSONGATE_HPP
#define JSONGATE_HPP

#include <string>
#include <vector>

#include "../../lib/json/single_include/nlohmann/json.hpp"

#define JSON_INPUT_DEFAULT_NAME "JSON"
#define JSON_PARSABLE NLOHMANN_DEFINE_TYPE_INTRUSIVE

class JsonGate
{
private:
    std::string name = JSON_INPUT_DEFAULT_NAME;
    std::vector<JsonGate> inputs;

protected:
    template <typename T>
    void setInputs(std::vector<T>);

public:
    void setName(std::string);

    std::string getName();
    std::vector<JsonGate> getInputs();

    JSON_PARSABLE(JsonGate, name, inputs)
};

inline void JsonGate::setName(std::string name) { this->name = name; }
template <typename T>
inline void JsonGate::setInputs(std::vector<T> inputs)
{
    std::vector<JsonGate> jsonInputs;

    for (auto &&input : inputs)
        jsonInputs.push_back(*(JsonGate *)input);

    this->inputs = jsonInputs;
}

inline std::string JsonGate::getName() { return name; }
inline std::vector<JsonGate> JsonGate::getInputs() { return inputs; }

#endif
