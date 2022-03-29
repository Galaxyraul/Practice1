/** 
 * @file Droide.h
 * @author Casipro Gramo
 *
 * @date Fecha estelar 20160309
 */

#ifndef DROIDE_H
#define DROIDE_H

#include <string>

/**
 * @brief
 */
class Droide
{
   private:
      static int _numDroides; ///< Número de droides instanciados
      int _idD = 0;           ///< Identificador del droide
      std::string _marca ="";     ///< Marca del droide
      std::string _modelo ="";    ///< Modelo de droide
      int _numberOfMissions = 0;
public:
    int getNumberOfMissions() const;

    void setNumberOfMissions(int numberOfMissions);

public:
      Droide ( );

      Droide ( std::string marca, std::string modelo,int numberOfMissions );

      Droide ( const Droide& orig );

      virtual ~Droide ( );

      int getIdD ( ) const;

      const Droide&  setModelo ( std::string modelo );

      std::string getModelo ( ) const;

      const Droide&  setMarca ( std::string marca );

      std::string getMarca ( ) const;

      std::string toCSV () const;

      Droide& operator= ( const Droide& otro );

      const void fromCSV(std::string CSV);

      const void newMission();

      const bool needsMaintenance();

      bool operator==(const Droide &rhs) const;
};

#endif /* DROIDE_H */

