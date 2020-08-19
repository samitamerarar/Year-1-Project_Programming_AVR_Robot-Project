if(nbMesures < 30)
	{
		uint8_t distance = captDistance.calculerDistanceCm();	
	
		tableauMesures[nbMesures++] = distance;
	}
	
	else
	{
		for (int i = 0; i < nbMesures; i++)
		{
			uart_send(tableauMesures[i]);
		}
		
		moteur.arreter();
		
		int nbCompteurs = 0;
		int compteur1;
		int somme = 0;
		
		for (int i = 0; i < nbMesures - 1; i++)
		{
			int counter = 0;
			for (int j = i; j < nbMesures - 1 ; i++)
			{
				if(tableauMesures[i] >= tableauMesures[j] && tableauMesures[i] < tableauMesures[j] + 1)
					counter++;
			}
			
			if(counter < 10)
			{
				if(tableauMesures[i] < tableauMesures[i + 1])
				{
					nbCompteurs++;
					somme += compteur1;
					compteur1 = 0;
				}			
				
				if(tableauMesures[i] == tableauMesures[i + 1])
					compteur1++;
			}
			else
				break;
		}
	}
