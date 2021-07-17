/*
** EPITECH PROJECT, 2021
** data_management.h
** File description:
** file for struct and enum who are use for data import
*/

#ifndef DATA_BASE_H_
#define DATA_BASE_H_

#include <SFML/Graphics.h>
#include <SFML/Graphics/Export.h>
#include <SFML/Audio/Export.h>
#include <SFML/Audio/SoundStatus.h>
#include <SFML/Audio/Types.h>
#include <SFML/System/InputStream.h>
#include <SFML/System/Time.h>

#define NBMAX_TEXTURE 61

#define NBMAX_SONG 1

typedef enum data_pnj_e
{
    TPLAYER,
    TSTOP,
    TGAME,
    TPAUSE,
    TGRASS,
    TROAD,
    TROAD_TURN,
    TFENCE_H,
    TFENCE_V,
    THGRASS,
    THOUSE,
    TTHREE,
    TLAC_00,
    TLAC_01,
    TLAC_02,
    TLAC_03,
    TLAC_10,
    TLAC_11,
    TLAC_20,
    TELE_F,
    TLOUTRE,
    TMENU_PAUSE,
    TBACK_MENU,
    TBACK_MENU2,
    TCONTINUE,
    TQUIT,
    TMENU,
    TSETTING,
    TRETOUR,
    TMUSIC,
    TCASE,
    TBAR,
    TFLECHE,
    TBALL_F,
    TBALL_L,
    TBALL_I,
    TMAGE_F,
    TMAGE_L,
    TMAGE_I,
    TMAGE_FL,
    TCADRE,
    TGENERAL,
    TPV,
    TPV_CADRE,
    TBULLE,
    TCADRRE,
    TCADRRRE,
    TCADRRRRE,
    TPOKEBAG,
    TROUCOOL,
    TROUCOOL_D,
    TBULBA,
    TBULBA_D,
    TPIKACHU,
    TPOK_BANDE,
    TBLANC,
    TSKY1,
    TSKY2,
    TCADRE_FLECHE,
    TCADRE_FLECHE_D,
    TCURSOR,
}data_pnj_t;
/*    type to add when texture
 TGOBELIN,
   TELEMENTAIR**/
typedef enum data_ogg_e
{
    RALPH,
}data_ogg_t;

typedef struct texture_s
{
    sfTexture **pnj;
    sfMusic **ogg;
    sfFont *font;
}texture_t;

/////////////////////////////////////////////////
/// \brief get a texture
///
/// \param drw structure des donne
/// \param type number associer a la texture voulu
///
/////////////////////////////////////////////////
sfTexture *get_textur(texture_t *drw, data_pnj_t type);

/////////////////////////////////////////////////
/// \brief get a texture
///
/// \param drw struct des donne
/// \param type number assosier song voulu
///
/////////////////////////////////////////////////
sfMusic *get_song(texture_t *drw, data_ogg_t type);

/////////////////////////////////////////////////
/// \brief load the texture
/// load with the define nb max de textur \n
///
/// PRIVATE fonction
///
/////////////////////////////////////////////////
sfTexture **loading_texture(void);

/////////////////////////////////////////////////
/// \brief load the song with the prefab
/// load with the defin nb max song
///
/// PRIVATE fonction
///
/////////////////////////////////////////////////
sfMusic **loading_song(void);

#endif
