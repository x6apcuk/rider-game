#include <iostream>
using namespace std;

class Pupil {
 public:
  Pupil(string name, string fam_name) {
    first_name_ = name;
    second_name_ = fam_name;
  }
  void SetMath(int math) { math_ = math; }
  void SetRuLang(int ru_lang) { ru_lang_ = ru_lang; }
  void SetFhiz(int fhiz) { fhiz_ = fhiz; }
  void GetAverage() {
    UpgradeAverageMark();
    cout << average_ << endl;
  }

 private:
  void UpgradeAverageMark() {
    average_ = (float)(math_ + ru_lang_ + fhiz_) / 3;
  }
  string first_name_;
  string second_name_;
  int math_, ru_lang_, fhiz_;
  float average_;
};

int main() {
  Pupil arsl("Arslan", "Abdrazakov");
  arsl.SetMath(10);
  arsl.SetRuLang(10);
  arsl.SetFhiz(10);
  arsl.GetAverage();
}