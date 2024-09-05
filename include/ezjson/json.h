#ifndef JSON_H
#define JSON_H

#include <simdjson.h>
#include <string>

using namespace simdjson;

namespace ezjson {

class json {
  public:
    json();
    json(std::string_view json);
    json(const json &j)
        : _ps()
        , _doc(j._doc)
        , _parser() {}
    json(json &&j)
        : _ps(std::move(j._ps))
        , _doc(std::move(j._doc))
        , _parser(std::move(j._parser)) {}
    dom::element operator[](std::string_view key);
    std::string prettify();
    void parse(std::string_view json);
    inline dom::element &get() {
        return this->_doc;
    }
    friend std::ostream &operator<<(std::ostream &stream, const json &json);

  private:
    padded_string _ps;
    dom::element _doc;
    dom::parser _parser;
};

} // namespace ezjson

#endif /* JSON_H */
