#include <iostream>
#include <fstream>
#include <vector>



class Aeroport
{
    private:
        std::string m_nom;
        int m_nombrePistes;
        int m_nbPlaceAuSol;
        int m_delaiAttenteSol;
        int m_tempsAccesPiste;
        int m_tempsAtterDecol;
        int m_tempsAntiCol;
        int m_tempsBoucleAttente;
        int liaisons;

    public:

        Aeroport()
        {
            std::string m_nom = "";
            m_nombrePistes = 0;
            m_nbPlaceAuSol = 0;
            m_delaiAttenteSol = 0;
            m_tempsAccesPiste = 0;
            m_tempsAtterDecol = 0;
            m_tempsAntiCol = 0;
            m_tempsBoucleAttente = 0;

        }

        void setNom(std::string _nom)
        {
            m_nom = _nom;
        }

        void setNombrePistes(int _nombrePistes)
        {
            m_nombrePistes = _nombrePistes;
        }

        void setNbPlacesAuSol(int _nbPlaceAuSol)
        {
            m_nbPlaceAuSol = _nbPlaceAuSol;
        }

        void setDelaiAttenteSol(int _delaiAttenteSol)
        {
            m_delaiAttenteSol = _delaiAttenteSol;
        }

        void setTempsAccesPiste(int _tempsAccesPiste)
        {
            m_tempsAccesPiste = _tempsAccesPiste;
        }

        void setTempsAtterDecol(int _tempsAtterDecol)
        {
            m_tempsAtterDecol = _tempsAtterDecol;
        }

        void setTempsAntiCol(int _tempsAntiCol)
        {
            m_tempsAntiCol = _tempsAntiCol;
        }

        void setTempsBoucleAttente(int _tempsBoucleAttente)
        {
            m_tempsBoucleAttente = _tempsBoucleAttente;
        }

        void Afficher()
        {
            std::cout << "Nom de l'aeroport:  " << m_nom <<std::endl;
            std::cout << "Nombre de pistes:  " << m_nombrePistes << std::endl;
            std::cout << "Nombre de places au sol:  " << m_nbPlaceAuSol << std::endl;
            std::cout << "Delai d'attente au sol:  " << m_delaiAttenteSol <<std::endl;
            std::cout << "Temps d'acces au pistes:  " << m_tempsAccesPiste <<std::endl;
            std::cout << "Temps d'atterissage/decolage:  " << m_tempsAtterDecol <<std::endl;
            std::cout << "Temps d'anticollision:  " << m_tempsAntiCol <<std::endl;
            std::cout << "Temps en boucle d'attente:  " << m_tempsBoucleAttente <<std::endl;
            std::cout <<std::endl<<std::endl<<std::endl;
        }

};


class TousAeroports
{
    private:
        std::vector <Aeroport> m_tousAeroports;
    public:
        TousAeroports()
        {
            std::ifstream ifs{"donneesAero.txt"};
            for(int i = 0; i< 7; i++)
            {
                m_tousAeroports.push_back(Aeroport()) ;


                if (!ifs) //Si probleme d'ouverture du ficher
                {
                throw std::runtime_error( "Impossible d'ouvrir en lecture donneesAero.txt" ); //Traitement et renvoi de l'erreur associee
                }

                std::string _nom;
                ifs>> _nom;
                if ( ifs.fail() ) //Si probleme de lecture de l'ordre
                {
                    throw std::runtime_error("Probleme lecture nom");
                }
                m_tousAeroports[i].setNom(_nom);



                int _nbPistes;
                ifs>> _nbPistes;
                if ( ifs.fail() ) //Si probleme de lecture de l'ordre
                {
                    throw std::runtime_error("Probleme lecture nbPlaceAuSol");
                }
                m_tousAeroports[i].setNombrePistes(_nbPistes);




                int _nbPlaceSol;
                ifs>> _nbPlaceSol;
                if ( ifs.fail() ) //Si probleme de lecture de l'ordre
                {
                    throw std::runtime_error("Probleme lecture nbPlaceAuSol");
                }
                m_tousAeroports[i].setNbPlacesAuSol(_nbPlaceSol);


                int _delAtSol;
                ifs>> _delAtSol;
                if ( ifs.fail() ) //Si probleme de lecture de l'ordre
                {
                    throw std::runtime_error("Probleme lecture delaiAttenteSol");
                }
                m_tousAeroports[i].setDelaiAttenteSol(_delAtSol);


                int _tempsAccesPiste;
                ifs>> _tempsAccesPiste;
                if ( ifs.fail() ) //Si probleme de lecture de l'ordre
                {
                    throw std::runtime_error("Probleme lecture tempsAccesPiste");
                }
                m_tousAeroports[i].setTempsAccesPiste(_tempsAccesPiste);


                int _tempsAtterDecol;
                ifs>> _tempsAtterDecol;
                if ( ifs.fail() ) //Si probleme de lecture de l'ordre
                {
                    throw std::runtime_error("Probleme lecture tempsAtterDecol");
                }
                m_tousAeroports[i].setTempsAtterDecol(_tempsAtterDecol);


                int _tempsAntiCol;
                ifs>> _tempsAntiCol;
                if ( ifs.fail() ) //Si probleme de lecture de l'ordre
                {
                    throw std::runtime_error("Probleme lecture tempsAntiCol");
                }
                m_tousAeroports[i].setTempsAntiCol(_tempsAntiCol);


                int _tempsBoucleAttente;
                ifs>> _tempsBoucleAttente;
                if ( ifs.fail() ) //Si probleme de lecture de l'ordre
                {
                    throw std::runtime_error("Probleme lecture tempsBoucleAttente");
                }
                m_tousAeroports[i].setTempsBoucleAttente(_tempsBoucleAttente);
            }
        }

        void afficherTousAeroports()
        {
            for(int i = 0; i< 7 ; i++)
            {
                m_tousAeroports[i].Afficher();
            }
        }
};





int main()
{
    TousAeroports reseau = TousAeroports();
    reseau.afficherTousAeroports();

    return 0;
}
