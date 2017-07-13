#include "DicoSynonymes.h"
#include "gtest/gtest.h"

using namespace std;
using namespace TP3;

TEST(ArbreSimple, NbRadicaux){
	DicoSynonymes DicoTest;
	DicoTest.ajouterRadical("banane");
	ASSERT_EQ(1, DicoTest.nombreRadicaux());
}

TEST(ArbreSimple, Appartient){
	DicoSynonymes DicoTest;
	DicoTest.ajouterRadical("banane");
	ASSERT_TRUE(DicoTest.appartient("banane"));
}

TEST(ArbreSimple, Vide){
	DicoSynonymes DicoTest;
	ASSERT_TRUE(DicoTest.estVide());
}

TEST(ArbreSimple, NonVide){
	DicoSynonymes DicoTest;
	DicoTest.ajouterRadical("banane");
	ASSERT_FALSE(DicoTest.estVide());
}
