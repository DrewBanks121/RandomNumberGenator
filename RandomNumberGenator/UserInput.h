#ifndef UserInput_H
#define UserInput_H

class UserInput {

public:
	UserInput();
	~UserInput();

	
	void checkUserInput();
	void gameStart();
	void GenerateNumb();
	void GameRestart();
	

	double outPutUserNumber();

private:
	double UserNumber;
	double GeneratedNumb;
	double NumberOfGuesses;
};


#endif // !UserInput_H

