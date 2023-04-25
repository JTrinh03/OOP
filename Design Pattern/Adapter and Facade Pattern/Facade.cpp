#include <iostream>
#include <string>

using namespace std;

class DVDPlayer {
	public:
		string turnOn() const { return "DVD Player is turned on!\n"; }
		string turnOff() const { return "DVD Player is turned off!\n"; }
		string pause() const { return "DVD Player is paused!\n"; }   
};

class Screen {
	public:
		string turnOn() const { return "Screen is turned on!\n"; }
		string turnOff() const { return "Screen is turned off!\n"; }
};

class Amplifier {
	public:
		string turnOn() const { return "Amplifier is turned on!\n"; }
		string turnOff() const { return "Amplifier is turned off!\n"; }
		string setDVDinput() const { return "Amplifier DVD Input Mode!\n"; }
		string setCDinput() const { return "Amplifier CD Input Mode!\n"; }  
		string volumeLow() const { return "Amplifier Volume is Low!\n"; }  
		string volumeMedium() const { return "Amplifier Volume is Medium!\n"; }
		string volumeHigh() const { return "Amplifier Volume is High!\n"; }  

};

class Speaker {
	public:
		string turnOn() const { return "Speaker is turned on!\n"; }
		string turnOff() const { return "Speaker is turned off!\n"; }
};

class Light {
	public:
		string turnOn() const { return "Light is turned on!\n"; }
		string turnOff() const { return "Light is turned off!\n"; }
};

class Laptop {};

class Facade {
	protected:
  		DVDPlayer *dvdplayer_;
  		Screen *screen_;
  		Amplifier *amplifier_;
  		Speaker *speaker_;
  		Light *light_;

  	public:
  		Facade(
  				DVDPlayer *dvdplayer = nullptr,
  				Screen *screen = nullptr,
  				Amplifier *amplifier = nullptr,
  				Speaker *speaker = nullptr,
  				Light *light = nullptr) {
    				this->dvdplayer_ = dvdplayer ?: new DVDPlayer;
    				this->screen_ = screen ?: new Screen;
    				this->amplifier_ = amplifier ?: new Amplifier;
    				this->speaker_ = speaker ?: new Speaker;
    				this->light_ = light ?: new Light; 
  				}

  		~Facade() {
  			delete dvdplayer_;
  			delete screen_;
  			delete amplifier_;
  			delete speaker_;
  			delete light_;
  		}


  		string watchMovie() {
  			string result = "Facade initializes Watching Movie:\n";
  			result += this->dvdplayer_->turnOn();
  			result += this->screen_->turnOn();
  			result += this->amplifier_->turnOn();
  			result += this->speaker_->turnOn();
  			result += this->amplifier_->setDVDinput();
  			result += amplifier_->volumeMedium();
  			result += this->light_->turnOff();
  			return result;
  		}

};

void Client(Facade *facade) {
	cout << facade->watchMovie();
}


int main() {
  	DVDPlayer *dvdplayer = new DVDPlayer;
	Screen *screen = new Screen;
  	Amplifier *amplifier = new Amplifier;
  	Speaker *speaker = new Speaker;
  	Light *light = new Light;

  	Facade *facade = new Facade(dvdplayer, screen, amplifier, speaker, light);
  	Client(facade);

  	delete facade;
}


