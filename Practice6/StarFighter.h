/** 
 * @file StarFighter.h
 * @author Casipro Gramo
 *
 * @date Fecha estelar 20160309
 */

#ifndef STARFIGHTER_H
#define STARFIGHTER_H

#include <string>
#include "Part.h"

/**
 * @brief
 */
class StarFighter
{
   private:
      static int _numStarFighters; ///< Número de objetos de esta clase instanciados
      int _numOfComponents = 0;
      int _idSF=0; ///< Identificador único de la nave
      std::string _marca = ""; ///< Marca de la nave (parece que las VW contaminan más)
      std::string _modelo = ""; ///< Modelo de la nava
      int _numPlazas = 0; ///< Número de plazas de la nave
      Part *_components[50];

   public:
      StarFighter ();

      StarFighter ( std::string marca, std::string modelo );

      StarFighter ( const StarFighter& orig );

      virtual ~StarFighter ( );

      const StarFighter& setNumPlazas ( int numPlazas );

      int getNumPlazas ( ) const;

      const StarFighter& setModelo ( std::string modelo );

      std::string getModelo ( ) const;

      const StarFighter& setMarca ( std::string marca );

      std::string getMarca ( ) const;

      int getIdSF ( ) const;

      std::string toCSV () const;

      StarFighter& operator= ( const StarFighter& otro );

      const void fromCSV(std::string CSV);

      const void newPart();

     const void newPart(const std::string& name,float weight);

      const void ReplacePart(int pos);

      const void RemovePart(int pos);

      float computeWeight();

};



#endif /* STARFIGHTER_H */

