#include <iostream>
#include <string>

using namespace std;

void SendSms(const string& number, const string& message) {
  cout << "Send '" << message << "' to number " << number << endl;
}
void SendEmail(const string& email, const string& message) {
  cout << "Send '" << message << "' to e-mail " << email << endl;
}

class INotifier {
 public:
  virtual void Notify(const string& message) = 0;
};

class SmsNotifier : public INotifier {
 private:
  string number;

 public:
  SmsNotifier(string num) : number(num) {}

  void Notify(const string& message) override { SendSms(number, message); }
};

class EmailNotifier : public INotifier {
 private:
  string email;

 public:
  EmailNotifier(string em) : email(em) {}

  void Notify(const string& message) override { SendEmail(email, message); }
};

void Notify(INotifier& notifier, const string& message) {
  notifier.Notify(message);
}

int main() {
  SmsNotifier sms("+74956498329");
  EmailNotifier email("black_cat_sajik_2003@mail.ru");

  Notify(sms, "Test message 1");
  Notify(email, "Test message 2");

  return 0;
}