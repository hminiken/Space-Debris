# #####################################################################
# ## Program name: makefile
# ## Author: Hillary Miniken
# ## Date: 08/13/2019
# ## Description: makefile with gdb debugging, -wall warning flags, and
#									make clean functionality
# #####################################################################/

##Source: Canvas Module "Lecture: Makefiles"
# ##https://oregonstate.instructure.com/courses/1729284/pages/lecture-makefiles?module_item_id=18843011

CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
#CXXFLAGS += -O3
#LDFLAGS = -lboost_date_time
OBJS = main.o inputValidation.o Menu.o Space.o PickUpDebris.o UseDebris.o EnterCode.o StartSpace.o JetpackFuel.o
OBJS += Board.o Player.o Debris.o Display.o Game.o Leaderboard.o
SRCS = main.cpp inputValidation.cpp Menu.cpp Space.cpp PickUpDebris.cpp UseDebris.cpp EnterCode.cpp StartSpace.cpp JetpackFuel.cpp Board.cpp
SRCS += Player.cpp Debris.cpp Display.cpp Game.cpp Leaderboard.cpp

HEADERS =
#target: dependencies
#     rule to build
#
output: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o output
${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)


clean: 
	rm *.o output
