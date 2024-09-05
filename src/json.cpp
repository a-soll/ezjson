#include <ezjson/json.h>

namespace ezjson {

json::json() {}

json::json(std::string_view json)
    : _ps(json) {
    this->_doc = this->_parser.parse(this->_ps);
}

dom::element json::operator[](std::string_view key) {
    dom::element json;
    auto error = this->_doc[key].get(json);
    if (error) {
        std::cout << simdjson::prettify(this->_doc) << '\n';
        std::cout << "ERRO: " << key << '\n';
    }
    return this->_doc[key];
}

std::string json::prettify() {
    return simdjson::prettify(this->_doc);
}

void json::parse(std::string_view json) {
    this->_ps  = json;
    this->_doc = this->_parser.parse(this->_ps);
}

std::ostream &operator<<(std::ostream &stream, const json &json) {
    return stream << json._ps;
}

} // namespace ezjson
