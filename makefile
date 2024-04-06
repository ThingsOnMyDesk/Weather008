CC= g++
CFLAGS = -Wall -g

WeatherEXE: Weather008.o Quest.o FoodQuest.o LostGirl.o DiaperQuest.o BeachQuest1.o HelperObjectClass.o
	$(CC) $(CFLAGS) -o WeatherEXE Weather008.o Quest.o FoodQuest.o LostGirl.o DiaperQuest.o BeachQuest1.o HelperObjectClass.o

Weather008.o: Weather008.cpp Quest.h FoodQuest.h LostGirl.h DiaperQuest.h BeachQuest1.h HelperObjectClass.h
	$(CC) $(CFLAGS) -c Weather008.cpp

Quest.o: Quest.h

FoodQuest.o: FoodQuest.h Quest.h

LostGirl.o: LostGirl.h Quest.h

DiaperQuest.o: DiaperQuest.h Quest.h

BeachQuest1.o: BeachQuest1.h Quest.h

HelperObjectClass.o: HelperObjectClass.h
