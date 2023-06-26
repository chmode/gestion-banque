#include <stdio.h>
#include <conio.h>
#include <string.h>
typedef struct date{
	int jour,mois,annee;
};
typedef struct client {
	int cin;
	char nom[10],prenom[10],ville[10];
	struct date datdenes;
};
typedef struct comptbank {
	int CIN;
	int nemcompt;
	int dernope;
	char localiville[10];
	float as,os;
	struct date datdecre;
};
//**********************************************
	void AjoutClient(struct client t[],int taill,int *start){
		int i,j,exi;
		system("cls");
	printf("\t\t***************************\n");
	printf("\t\t*                         *\n");
	printf("\t\t*          MY BANCK       *\n");
	printf("\t\t*                         *\n");
	printf("\t\t***************************\n");
		for (i=*start;i<taill;i++){
			printf("	\n*****client numero %d.*****\n",i+1);
			printf("Donner le nom: ");
			fflush(stdin);
			scanf("%s",(t+i)->nom);
			printf("Donner le prenom: ");
			fflush(stdin);
			scanf("%s",(t+i)->prenom);
			printf("Donner la date de naissance:\n");
			do{
				printf("annee: ");
				scanf("%d",&(t+i)->datdenes.annee);
			}while((t+i)->datdenes.annee<1||(t+i)->datdenes.annee>2022);
			do{
				printf("mois: ");
				scanf("%d",&(t+i)->datdenes.mois);
			}while((t+i)->datdenes.mois<1||(t+i)->datdenes.mois>12);
			do{
				printf("le joure: ");
				scanf("%d",&(t+i)->datdenes.jour);
			}while((t+i)->datdenes.jour<1||(t+i)->datdenes.jour>31);

				do{
					exi=0;
					do{
			   printf("Donner le CIN: ");
			   scanf("%d",&(t+i)->cin);
					}while((t+i)->cin<=0);
			   for(j=0;j<i;j++){
			   	if((t+i)->cin==(t+j)->cin){
			   		printf("\t\tle CIN deja existe.\n");exi=1;getch();
				   }
			   }
		}while(exi==1);
			printf("Donner la ville: ");
			fflush(stdin);
			scanf("%s",(t+i)->ville);
			printf("le client est ajouter avec succes\n");getch();
		}
		*start=i;
	}
//***************************************************
	void CreationCompte (struct comptbank t[],int taill,struct client t1[],int *clienttaill,int *startcompte){
		int i,j,j1,j2,exi,exi1,cindeja=0;
		system("cls");
	printf("\t\t***************************\n");
	printf("\t\t*                         *\n");
	printf("\t\t*          MY BANCK       *\n");
	printf("\t\t*                         *\n");
	printf("\t\t***************************\n");

		for (i=*startcompte;i<taill;i++){
			printf("	\n*****client %d.*****\n",i+1);
			do{
				exi1=0;
				do{
			printf("Donner le cin de client: ");
			scanf("%d",&(t+i)->CIN);
				}while((t+i)->CIN<=0);
			for(j1=0;j1<*clienttaill;j1++){
				if((t+i)->CIN==(t1+j1)->cin){
					printf("client existe...\n");
					exi1=1;
				}

				}if(exi1==0){printf("CIN n'existe pas.\n");}
			}while(exi1==0);

		/*//***********
        if(i!=0){
            for(j2=0;j2<taill;j2++){
                    if(i==j2){cindeja=1;break;}
                if((t+i)->CIN==(t+j2)->CIN){
                    printf("ce client deja un compte.\n");getch();
                    //exit(0);
                }
            }
        }if(cindeja==1){break;}
		//************/



				do{
					exi=0;
					do{
			   printf("Donner le numero de compte: ");
			   scanf("%d",&(t+i)->nemcompt);
					}while((t+i)->nemcompt<=0);
			   for(j=0;j<i;j++){
			   	if((t+i)->nemcompt==(t+j)->nemcompt){
			   		printf("\t\tle numero de compte deja existe.\n");exi=1;getch();
				   }
			   }
		}while(exi==1);
		do{
			printf("Donner le derniere operation: 1)Retrait 2)Virement 3)Depot: ");
			scanf("%d",&(t+i)->dernope);
		}while((t+i)->dernope<1||(t+i)->dernope>3);
		printf("Donner la ville de creation du compte: ");
		fflush(stdin);
		scanf("%s",(t+i)->localiville);
		do{
		printf("Donner le solde actuel: ");
		scanf("%f",&(t+i)->as);
		}while((t+i)->as<0);
		do{
		printf("Donner le ancien solde: ");
		scanf("%f",&(t+i)->os);
		}while((t+i)->os<0);
		printf(" Donner la date de creation de compte.\n");
			do{
				printf("annee: ");
				scanf("%d",&(t+i)->datdecre.annee);
			}while((t+i)->datdecre.annee<1||(t+i)->datdecre.annee>2022);
			do{
				printf("mois: ");
				scanf("%d",&(t+i)->datdecre.mois);
			}while((t+i)->datdecre.mois<1||(t+i)->datdecre.mois>12);
			do{
				printf("le joure: ");
				scanf("%d",&(t+i)->datdecre.jour);
			}while((t+i)->datdecre.jour<1||(t+i)->datdecre.jour>31);
			printf("le compte cree avec succes\n");getch();
		}
		*startcompte=i;
	}


//***************************************************
	void Virement (struct comptbank t1[] ,int *compttaill){
		int comptini,tem1=0,cp1;
		int comptavers,tem2=0,cp2;
		float montantverse;
		int i;
	printf("\t\t***************************\n");
	printf("\t\t*                         *\n");
	printf("\t\t*          MY BANCK       *\n");
	printf("\t\t*                         *\n");
	printf("\t\t***************************\n");
        do{
		printf("\nDonner le numero de copmte initial: ");
		scanf("%d",&comptini);
        }while(comptini<=0);
        do{
		printf("Donner le numero de copmte a verse: ");
		scanf("%d",&comptavers);
        }while(comptavers<=0);
			for(i=0;i<*compttaill;i++){
				if(comptini==(t1+i)->nemcompt){
					tem1=1;
					cp1=i;
				}
			}
			for(i=0;i<*compttaill;i++){
				if(comptavers==(t1+i)->nemcompt){
					tem2=1;
					cp2=i;
				}
			}
			if(tem1==0){
				printf("\t\tcopmte initial ne existe pas!!");getch();
			}
			if(tem2==0){
				printf("\t\tcopmte a verse ne existe pas!!");getch();
			}

			if(tem1==1&&tem2==1){
		printf("*** %d ---> %d ***\n",comptini,comptavers);
		do{
		printf("  Donner le montant verse: ");
		scanf("%f",&montantverse);
		}while(montantverse<1);
		if((t1+cp1)->as>=montantverse){
			(t1+cp1)->os=(t1+cp1)->as;
			(t1+cp2)->os=(t1+cp2)->as;
			(t1+cp1)->as=(t1+cp1)->as-montantverse;
			(t1+cp2)->as=(t1+cp2)->as+montantverse;
			(t1+cp1)->dernope=2;
			printf("le solde est versee avec succes\n");getch();

		}else{
			printf("\t\tsolde insevisente!!\n");getch();
		}
	}

	}
//***************************************************
	void ListerClients (struct client t[],int *taill){
		int i;
	printf("\t\t***************************\n");
	printf("\t\t*                         *\n");
	printf("\t\t*          MY BANCK       *\n");
	printf("\t\t*                         *\n");
	printf("\t\t***************************\n");
		for(i=0;i<*taill;i++){
			printf("\n****client %d.****\n",i+1);
			printf("le CIN est: %d.\n",(t+i)->cin);
			printf("le nome et prenome est: %s %s.\n",(t+i)->nom,(t+i)->prenom);
			printf("la ville est: %s.\n",(t+i)->ville);
			printf("la date de naissance est: %d/%d/%d.\n",(t+i)->datdenes.jour,(t+i)->datdenes.mois,(t+i)->datdenes.annee);
		}getch();
	}
//***************************************************
	void ListerComptes (struct comptbank t[],int *taill){
		int i;
	printf("\t\t***************************\n");
	printf("\t\t*                         *\n");
	printf("\t\t*          MY BANCK       *\n");
	printf("\t\t*                         *\n");
	printf("\t\t***************************\n");
		for(i=0;i<*taill;i++){
			printf("\n****compte %d.****\n",i+1);
			printf("le CIN de proprietaire: %d.\n",(t+i)->CIN);
			printf("le numero de compte est: %d.\n",(t+i)->nemcompt);
			if((t+i)->dernope==1){
			printf("le dernier operation est: retrait.\n");
		}
			if((t+i)->dernope==2){
			printf("le dernier operation est: virement.\n");
		}else if((t+i)->dernope==3){
			printf("le dernier operation est: Depot.\n");
		}
			printf("la ville de creation du compte est: %s.\n",(t+i)->localiville);
			printf("solde actuel est: %.2fDH.\n",(t+i)->as);
			printf("ancien solde est: %.2fDH.\n",(t+i)->os);
			printf("la date de ceation de compte est: %d/%d/%d.\n",(t+i)->datdecre.jour,(t+i)->datdecre.mois,(t+i)->datdecre.annee);
		}getch();
	}
//***************************************************
	void DetailsClient (struct client t[],int *taill){
		int i,clcher,tm=0;
	printf("\t\t***************************\n");
	printf("\t\t*                         *\n");
	printf("\t\t*          MY BANCK       *\n");
	printf("\t\t*                         *\n");
	printf("\t\t***************************\n");
		do{
		printf("\nDonner le CIN de client cherche: ");
		scanf("%d",&clcher);
		}while(clcher<=0);
		for(i=0;i<*taill;i++){
			if(clcher==(t+i)->cin){
			printf("    ****client %d.****\n",i+1);
			printf("le CIN est: %d.\n",(t+i)->cin);
			printf("le nome et prenome est: %s %s.\n",(t+i)->nom,(t+i)->prenom);
			printf("la ville est: %s.\n",(t+i)->ville);
			printf("la date de naissance est: %d/%d/%d.\n",(t+i)->datdenes.jour,(t+i)->datdenes.mois,(t+i)->datdenes.annee);
			getch();
			tm=1;
			}if(tm==1){
                break;
			}
		}if(tm==0){printf("\t\t----->CIN Donne ne existe pas!!<-----\n");getch();}
	}
//***************************************************
	void DetailsCompte (struct comptbank t[],int *taill){
		int i,clcher,tm=0;
	printf("\t\t***************************\n");
	printf("\t\t*                         *\n");
	printf("\t\t*          MY BANCK       *\n");
	printf("\t\t*                         *\n");
	printf("\t\t***************************\n");
		do{
		printf("\nDonner le numero de compte cherche: ");
		scanf("%d",&clcher);
		}while(clcher<=0);
		for(i=0;i<*taill;i++){
			if(clcher==(t+i)->nemcompt){
			printf("    ****compte %d.****\n",i+1);
			printf("le CIN est: %d.\n",(t+i)->CIN);
			printf("le numero de compte.\n",(t+i)->nemcompt);
			printf("derniere operation\n");
			if((t+i)->dernope==1){
                printf("Retrait\n");
			}else if((t+i)->dernope==2){
                printf("Virement\n");
			}else{
                printf("Depot\n");
			}
			printf("la ville de creation du compte: %s\n",(t+i)->localiville);
			printf("solde actuel est: %.2f\n",(t+i)->as);
			printf("ancien solde est: %.2f\n",(t+i)->os);
			printf("la date de creation de compte est: %d/%d/%d.\n",(t+i)->datdecre.jour,(t+i)->datdecre.mois,(t+i)->datdecre.annee);
			tm=1;getch();
			}if(tm==1){
                break;
			}
		}if(tm==0){printf("\t\t----->numero Donne ne existe pas!!<-----\n");getch();}
	}

//***************************************************
void Depot (struct comptbank t1[] ,int *compttaill){
		int numdecompt,tem1=0;
		float montantdepot;
		int i;
	printf("\t\t***************************\n");
	printf("\t\t*                         *\n");
	printf("\t\t*          MY BANCK       *\n");
	printf("\t\t*                         *\n");
	printf("\t\t***************************\n");
        do{

		printf("\nDonner le numero de compte: ");
		scanf("%d",&numdecompt);
        }while(numdecompt<=0);
			for(i=0;i<*compttaill;i++){
				if(numdecompt==(t1+i)->nemcompt){
					tem1=1;
					do{
                    printf("Donner le montant a depot: ");
                    scanf("%f",&montantdepot);
					}while(montantdepot<1);
					(t1+i)->os=(t1+i)->as;
                    (t1+i)->as=(t1+i)->as+montantdepot;
					(t1+i)->dernope=3;
					printf("le solde est depot avec succes\n");getch();
				}
			}
			if(tem1==0){
				printf("\t\tnumero de copmte ne existe pas!!\n");getch();
			}


	}
//***************************************************
void Retrait(struct comptbank t1[] ,int *compttaill){
		int numdecompt,tem1=0;
		float montantretrait;
		int i;
	printf("\t\t***************************\n");
	printf("\t\t*                         *\n");
	printf("\t\t*          MY BANCK       *\n");
	printf("\t\t*                         *\n");
	printf("\t\t***************************\n");
        do{
		printf("\nDonner le numero de compte: ");
		scanf("%d",&numdecompt);
        }while(numdecompt<=0);
			for(i=0;i<*compttaill;i++){
				if(numdecompt==(t1+i)->nemcompt){
					tem1=1;
					do{
                    printf("Donner le montant a retrait: ");
                    scanf("%f",&montantretrait);
					}while(montantretrait<1);
                        if((t1+i)->as>=montantretrait){
                           (t1+i)->os=(t1+i)->as;
                           (t1+i)->as=(t1+i)->as-montantretrait;
					       (t1+i)->dernope=1;
					       printf("le solde est retrait avec succes.\n");getch();
                        }else{
                            printf("solde insevisente!!.\n");getch();
                        }
				}
			}
			if(tem1==0){
				printf("numero de copmte ne existe pas!!\n");getch();
			}


	}
//***************************************************
void SupprimerClient (struct client t[],int *taill,struct comptbank t1[],int *taillcomptbank,int *cli,int *coi){
    int cinsupp,i,j,tem=0;
	printf("\t\t***************************\n");
	printf("\t\t*                         *\n");
	printf("\t\t*          MY BANCK       *\n");
	printf("\t\t*                         *\n");
	printf("\t\t***************************\n");
            do{
            printf("\nDonner le CIN de client a supprimer: ");
            scanf("%d",&cinsupp);
            }while(cinsupp<=0);
            for(i=0;i<*taill;i++){
                if((t+i)->cin==cinsupp){
                        tem=1;
                            if(i==*taill-1){
                                *taill=*taill-1;
                                *cli=*cli-1;
                                t=(struct client*)realloc(t,*taill*sizeof(struct client));
                                printf("le client est supprimer avec succes.\n");getch();
                                CloturerCompte(t1,taillcomptbank,cinsupp,coi);
                            }else{
                    for(j=i;j<*taill-1;j++){
                        (t+j)->cin=(t+j+1)->cin;
                        strcpy((t+j)->nom,(t+j+1)->nom);
                        strcpy((t+j)->prenom,(t+j+1)->prenom);
                        strcpy((t+j)->ville,(t+j+1)->ville);
                        (t+j)->datdenes.jour=(t+j+1)->datdenes.jour;
                        (t+j)->datdenes.mois=(t+j+1)->datdenes.mois;
                        (t+j)->datdenes.annee=(t+j+1)->datdenes.annee;
                    }
                        *taill=*taill-1;
                        *cli=*cli-1;
                        t=(struct client*)realloc(t,*taill*sizeof(struct client));
                        printf("le client est supprimer avec succes.\n");getch();
                        CloturerCompte(t1,taillcomptbank,cinsupp,coi);
                            }
                }
                if(tem==1){break;}
            }if(tem==0){printf("\t\tCIN nexiste pas.\n");getch();}

}
//***************************************************
void CloturerCompte(struct comptbank t[],int *taillcomptbank,int cincb,int *coii){
            int tem=0,i,j;
            for(i=0;i<*taillcomptbank;i++){
                if((t+i)->CIN==cincb){
                        tem=1;
                            if(i==*taillcomptbank-1){
                                *taillcomptbank=*taillcomptbank-1;
                                *coii=*coii-1;
                                t=(struct comptbank*)realloc(t,*taillcomptbank*sizeof(struct comptbank));
                                printf("le compte de ce client est supprimer avec succes.\n");getch();
                            }else{
                    for(j=i;j<*taillcomptbank-1;j++){
                        (t+j)->CIN=(t+j+1)->CIN;
                        (t+j)->nemcompt=(t+j+1)->nemcompt;
                        (t+j)->dernope=(t+j+1)->dernope;
                        (t+j)->as=(t+j+1)->as;
                        (t+j)->os=(t+j+1)->os;
                        (t+j)->localiville[10]=(t+j+1)->localiville[10];
                        (t+j)->datdecre.jour=(t+j+1)->datdecre.jour;
                        (t+j)->datdecre.mois=(t+j+1)->datdecre.mois;
                        (t+j)->datdecre.annee=(t+j+1)->datdecre.annee;
                    }
                        *taillcomptbank=*taillcomptbank-1;
                        *coii=*coii-1;
                        t=(struct comptbank*)realloc(t,*taillcomptbank*sizeof(struct comptbank));
                        printf("le compte de ce client est supprimer avec succes.\n");getch();
                }
            }if(tem==1){break;}
            }if(tem==0){printf("pas de compte pour ce client.\n");getch();}


}
//***************************************************
void CloturerCompteplus(struct comptbank t[],int *taillcomptbank,int numcb){
            int tem=0,i,j;
            for(i=0;i<*taillcomptbank;i++){
                if((t+i)->nemcompt==numcb){
                        tem=1;
                            if(i==*taillcomptbank-1){
                                *taillcomptbank=*taillcomptbank-1;
                                t=(struct comptbank*)realloc(t,*taillcomptbank*sizeof(struct comptbank));
                                printf("le compte est supprimer avec succes.\n");getch();
                            }else{
                    for(j=i;j<*taillcomptbank-1;j++){
                        (t+j)->CIN=(t+j+1)->CIN;
                        (t+j)->nemcompt=(t+j+1)->nemcompt;
                        (t+j)->dernope=(t+j+1)->dernope;
                        (t+j)->as=(t+j+1)->as;
                        (t+j)->os=(t+j+1)->os;
                        (t+j)->localiville[10]=(t+j+1)->localiville[10];
                        (t+j)->datdecre.jour=(t+j+1)->datdecre.jour;
                        (t+j)->datdecre.mois=(t+j+1)->datdecre.mois;
                        (t+j)->datdecre.annee=(t+j+1)->datdecre.annee;
                    }
                        *taillcomptbank=*taillcomptbank-1;
                        t=(struct comptbank*)realloc(t,*taillcomptbank*sizeof(struct comptbank));
                        printf("le compte est supprimer avec succes.\n");getch();
                }
            }
            }if(tem==0){printf("pas de compte pour ce numero.\n");getch();}


}
//***************************************************

main()
{
    char code[5];
    printf("\n\t\tDonner le code: ");
    fflush(stdin);
    scanf("%s",code);
    if(strcmp(code,"emsi")==0){
        int choix;
        struct client *p1;
        int *p11;
        struct comptbank *p2;
        int *p22;
        int globaltem1=0,globaltem2=0;
        int *start1,*start2,star1=0,star2=0;
        start1=&star1;
        start2=&star2;
	for(;;){
            if(globaltem1>0){
            system("cls");
	printf("\t\t***************************\n");
	printf("\t\t*                         *\n");
	printf("\t\t*          MY BANCK       *\n");
	printf("\t\t*                         *\n");
	printf("\t\t***************************\n");
		printf("\n\n");
		printf("  1)Ajouter un client.\n");
		printf("  2)Cree un compte.\n");
		printf("  3)supprimer un client.\n");
		//printf("  4)supprimer un compte.\n");
		printf("  4)Retrait un montant.\n");
		printf("  5)Depot un montant.\n");
		printf("  6)Virement un montant.\n");
		printf("  7)Affiche les details d'un client.\n");
		printf("  8)Affiche toutes les details des clients.\n");
		printf("  9)Affiche les details d'un compte.\n");
		printf("  10)Affiche toutes les details des comptes.\n");
		printf("  11)exite.\n");
		do {
		printf("Donner voutre choix de: ");
		scanf ("%d",&choix);
	}while(choix<1||choix>11);
	if(choix==1){globaltem1++;}
	if(choix==2){globaltem2++;}
            }else{
            system("cls");
	printf("\t\t***************************\n");
	printf("\t\t*                         *\n");
	printf("\t\t*          MY BANCK       *\n");
	printf("\t\t*                         *\n");
	printf("\t\t***************************\n");
		printf("\n\n");
		printf("  1)Ajouter un client.\n");
		printf("  2)Cree un compte.\n");
		printf("  3)supprimer un client.\n");
		//printf("  4)supprimer un compte.\n");
		printf("  4)Retrait un montant.\n");
		printf("  5)Depot un montant.\n");
		printf("  6)Virement un montant.\n");
		printf("  7)Affiche les details d'un client.\n");
		printf("  8)Affiche toutes les details des clients.\n");
		printf("  9)Affiche les details d'un compte.\n");
		printf("  10)Affiche toutes les details des comptes.\n");
		printf("  11)exite.\n");
		do {
		printf("Donner voutre choix de: ");
		scanf ("%d",&choix);
		if(choix==2){printf("aucune client pour cree le compte.\n");getch();}
	}while(choix<1||choix>11||choix==2);
	if(choix==1){globaltem1++;}
	if(choix==2){globaltem2++;}
            }
//********************************************************************

		switch(choix)
					{
						case 1:
							{
							     system("cls");
								int ajou,ajouplus;
                                    printf("\t\t***************************\n");
                                    printf("\t\t*                         *\n");
                                    printf("\t\t*          MY BANCK       *\n");
                                    printf("\t\t*                         *\n");
                                    printf("\t\t***************************\n");
								if(globaltem1>=2){
								do{
								printf("Donner le nombre de client ajouter: ");
								scanf("%d",&ajouplus);
								}while(ajouplus<1);
                                        *p11=*p11+ajouplus;
                                    p1=(struct client*)realloc(p1,*p11*sizeof(struct client));
                                        if(p1==NULL){
                                            printf("memoire insuffisante!!\n");
                                            *p11=*p11-ajouplus;

                                        }else{
                                        AjoutClient(p1,*p11,start1);
                                        }

								}
								else{
								do{
								printf("Donner le nombre de client ajouter: ");
								scanf("%d",&ajou);
								}while(ajou<1);
								p1=(struct client*)malloc(ajou*sizeof(struct client));
								p11=&ajou;
								if (p1==NULL){
									printf("memoire insuffisante!!\n");
									break;
									}else{
										AjoutClient(p1,ajou,start1);
									}
								}

								break;
							}
						case 2:
							{   system("cls");
								int ajou1,ajouplus;
                                    printf("\t\t***************************\n");
                                    printf("\t\t*                         *\n");
                                    printf("\t\t*          MY BANCK       *\n");
                                    printf("\t\t*                         *\n");
                                    printf("\t\t***************************\n");
								if(globaltem2>=2){
								do{
								printf("Donner le nombre de compte ajouter: ");
								scanf("%d",&ajouplus);
								}while(ajou1<1);
                                        *p22=*p22+ajouplus;
                                    p2=(struct comptbank*)realloc(p2,*p22*sizeof(struct comptbank));
                                        if(p1==NULL){
                                            printf("memoire insuffisante!!\n");
                                            *p22=*p22-ajouplus;

                                        }else{
                                        CreationCompte(p2,*p22,p1,p11,start2);
                                        }

								}else{
								do{
								printf("Donner le nombre de compte ajouter: ");
								scanf("%d",&ajou1);
								}while(ajou1<1);

								struct comptbank *comptbank;
								p2=(struct comptbank*)malloc(ajou1*sizeof(struct comptbank));
								p22=&ajou1;
								if (p2==NULL){
									printf("memoire insuffisante!!\n");
								}else{
									CreationCompte(p2,ajou1,p1,p11,start2);
								}
								}

									break;
							}
						case 3:
							{
							     system("cls");
							    SupprimerClient(p1,p11,p2,p22,start1,start2);
							    break;
							}
						case 44:
							{
							     system("cls");
							    int numsup;
							    do{
                                    printf("Donner le numero de compte a supprimer: ");
                                    scanf("%d",&numsup);
							    }while(numsup<=0);
							    CloturerCompteplus(p2,p22,numsup);
							    break;
							}
						case 4:
							{
							    system("cls");
							    Retrait(p2,p22);
							    break;
							}
						case 5:
							{
							    system("cls");
							    Depot (p2,p22);
							    break;
							}
						case 6:
							{
							    system("cls");
								Virement (p2,p22);
								break;
							}
						case 7:
							{
							    system("cls");
								DetailsClient (p1,p11);
								break;
							}
						case 8:
							{
							    system("cls");
								ListerClients (p1,p11);
								break;
							}
						case 9:
							{
							    system("cls");
							    DetailsCompte (p2,p22);
							    break;
							}
						case 10:
							{
							    system("cls");
								ListerComptes (p2,p22);
								break;
							}
						case 11:
						{
							break;
						}

					}
					if(choix==11){
						system("cls");
                        printf("\t\t***************************\n");
                        printf("\t\t*                         *\n");
                        printf("\t\t*          MY BANCK       *\n");
                        printf("\t\t*                         *\n");
                        printf("\t\t***************************\n");
                            printf("\n\n\t\t------>GoodBye.<------\n\n");getch();
						if(globaltem1!=0){
						free(p1);
						p1=NULL;p11=NULL;
						}
						if(globaltem2!=0){
                            free(p2);
                            p2=NULL;p22=NULL;
						}
                            start1=NULL;start2=NULL;

						exit(0);
					}
				}
        }else{
            system("cls");
            printf("\n\n\t\t----->ERROR!!\n\n\t\t\t----->you are not authorized.");getch();
        }
	}


