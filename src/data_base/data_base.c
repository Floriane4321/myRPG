/*
** EPITECH PROJECT, 2021
** defender
** File description:
** data management
*/

#include "data_base.h"

#include <SFML/Graphics.h>
#include <SFML/Graphics/Export.h>
#include <SFML/Audio/Types.h>
#include <SFML/Audio/Export.h>
#include <SFML/Audio/SoundStatus.h>
#include <stdlib.h>
#include <SFML/Config.h>

sfMusic *sfMusic_createFromFile(char const *filename);

const char prefab_data_textur[][50] = {
    "image/player.png",
    "image/def_stop.png",
    "image/def_start.png",
    "image/def_pause.png",
    "image/def_herbe_nuit.jpg",
    "image/def_chemin_1_nuit.jpg",
    "image/def_chemin_nuit.jpg",
    "image/def_barriere_bois_1.png",
    "image/def_barriere_bois_verticale_1.png",
    "image/def_plante_a_consommer_nuit.png",
    "image/Maison_1.png",
    "image/def_arbre_1.png",
    "image/def_lac_00.jpg",
    "image/def_lac_01.jpg",
    "image/def_lac_02.jpg",
    "image/def_lac_03.jpg",
    "image/def_lac_10.jpg",
    "image/def_lac_11.jpg",
    "image/def_lac_20.jpg",
    "image/fire_elementaire.png",
    "image/menu_loutre.jpg",
    "image/def_menu_pause_2.png",
    "image/def_back_menu_3.png",
    "image/def_back_menu_4.png",
    "image/def_continue_to_play_3.png",
    "image/def_quit_pause_3.png",
    "image/menu.jpg",
    "image/rouage.png",
    "image/def_retour.png",
    "image/def_menu_music.png",
    "image/sprite_case.png",
    "image/bar_music_2.png",
    "image/def_fleche.png",
    "image/boule_de_feu.png",
    "image/def_eclair.png",
    "image/pic_de_glace.png",
    "image/def_mage_feu.png",
    "image/def_mage_foudre.png",
    "image/def_mage_glace.png",
    "image/def_fleches.png",
    "image/def_cadre.png",
    "image/general.png",
    "image/def_pv.png",
    "image/def_pv_cadre.png",
    "image/def_bulle_dialogue.png",
    "image/cadre.png",
    "image/cadre2.png",
    "image/cadre3.png",
    "image/invory_bag.png",
    "image/roucool_face.png",
    "image/roucool_dos.png",
    "image/bulbizarre_face.png",
    "image/bulbizarre_dos.png",
    "image/pikachu_face.png",
    "image/pkm_bande.png",
    "image/écran_blanc.jpg",
    "image/star_sky1.png",
    "image/star_sky2.jpg",
    "image/cadre_flèche.png",
    "image/cadre_flèche_d.png",
    "image/cursor.png",
};

const char prefab_data_song[][50] = {
    "image/epic_music.ogg",
};

sfTexture *get_textur(texture_t *drw, data_pnj_t type)
{
    return (drw->pnj[type]);
}

sfMusic *get_song(texture_t *drw, data_ogg_t type)
{
    return (drw->ogg[type]);
}

sfTexture **loading_texture(void)
{
    sfTexture **pnj = malloc(sizeof(sfTexture *) * (1 + NBMAX_TEXTURE));

    for (int i = 0; i < NBMAX_TEXTURE; i++) {
        pnj[i] = sfTexture_createFromFile(prefab_data_textur[i], NULL);
    }
    pnj[NBMAX_TEXTURE] = NULL;
    return (pnj);
}

sfMusic **loading_song(void)
{
    sfMusic **ogg = malloc(sizeof(sfMusic *) * (1 + NBMAX_SONG));

    for (int i = 0; i < NBMAX_SONG; i++) {
        ogg[i] = sfMusic_createFromFile(prefab_data_song[i]);
    }
    ogg[NBMAX_SONG] = NULL;
    return (ogg);
}
