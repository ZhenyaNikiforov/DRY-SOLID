/*- Задание-2 (переделка) -*/
#include <iostream> //-Я добавил
using namespace std;

/*-Копия оригинального текста-*/

#include <fstream>

class Printable
{
public:
  virtual ~Printable() = default;

  virtual std::string printAsHTML() const = 0;
  virtual std::string printAsText() const = 0;
  virtual std::string printAsJSON() const = 0;
};

/*-Дальнейшая переделка-*/

class DataText : public Printable
{
public:
  DataText(string data)
  {
    this->_data = data;
  }

  string printAsHTML() const override
  {
    return "";
  }

  string printAsText() const override
  {
    return this->_data;
  }

  string printAsJSON() const override
  {
    return "";
  }

private:
  string _data;
};

class DataHTML : public Printable
{
public:
  DataHTML(string data)
  {
    this->_data = data;
  }

  string printAsHTML() const override
  {
    return "<html>" + this->_data + "</html>";
  }

  string printAsText() const override
  {
    return "";
  }

  string printAsJSON() const override
  {
    return "";
  }

private:
  string _data;
};

class DataJSON : public Printable
{
public:
  DataJSON(string data)
  {
    this->_data = data;
  }

  string printAsHTML() const override
  {
    return "";
  }

  string printAsText() const override
  {
    return "";
  }

  string printAsJSON() const override
  {
    return "{\"data\": \"" + this->_data + "\"}";
  }

private:
  string _data;
};

void saveTo(ofstream &file, std::string data)
{
  file << data;
}

int main()
{
  string content = "Privet!";

  DataText _dataText(content);
  DataHTML _dataHtml(content);
  DataJSON _dataJson(content);

  ofstream textFile("textFile.txt");
  ofstream htmlFile("htmlFile.html");
  ofstream jsonFile("jsonFile.json");

  saveTo(textFile, _dataText.printAsText());
  saveTo(htmlFile, _dataHtml.printAsHTML());
  saveTo(jsonFile, _dataJson.printAsJSON());

  textFile.close();
  htmlFile.close();
  jsonFile.close();

  return 0;
}