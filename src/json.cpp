#include <ezjson/json.h>

namespace ezjson {

json::json() {}

json::json(std::string_view json)
    : _ps(json) {
    this->_doc = this->_parser.parse(this->_ps);
}

std::string json::prettify() {
    return simdjson::prettify(this->_doc);
}

dom::element json::operator[](std::string_view key) const {
    dom::element json;
    auto error = this->_doc[key].get(json);
    if (error) {
        std::cerr << "ERROR: NO_SUCH_KEY: \"" << key << "\"" << '\n';
        exit(1);
    }
    return json;
}

int32_t json::get_int32(std::string_view key) {
    return (int32_t)this->_doc[key].get_int64();
}

void json::parse(std::string_view json) {
    this->_ps  = json;
    this->_doc = this->_parser.parse(this->_ps);
}

std::ostream &operator<<(std::ostream &stream, const json &json) {
    return stream << json._ps;
}

} // namespace ezjson
