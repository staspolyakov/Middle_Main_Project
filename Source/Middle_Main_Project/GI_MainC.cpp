// Fill out your copyright notice in the Description page of Project Settings.


#include "GI_MainC.h"


UGI_MainC::UGI_MainC()
{
}

bool UGI_MainC::SetCurrentPlayerCount(int playerCount)
{
	if (playerCount>0)
	{
		CurrentPlayerCount=playerCount;
		return true;
	}
	return false;
}
