/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 19:28:30 by smontuor          #+#    #+#             */
/*   Updated: 2023/11/08 16:32:23 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
/******************************************************************************/
/*						Definizione BUFFER_SIZE se non definito in altro modo */
/******************************************************************************/
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
/******************************************************************************/
/*						Definizione FD_MAX se non definito in altro modo      */
/******************************************************************************/
# ifndef FD_MAX
#  define FD_MAX 4096
# endif
/******************************************************************************/
/*						Librerie di supporto								  */
/******************************************************************************/
# include <stdlib.h>
# include <unistd.h>
/******************************************************************************/
/*						Funzioni principale									  */
/******************************************************************************/
char	*get_next_line(int fd);
char	*ft_remainder_trim(char *remainder);
char	*ft_get_line(char *remainder);
char	*ft_read_line(int fd, char *temp_line);
/******************************************************************************/
/*						Funzioni di supporto								  */
/******************************************************************************/
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlcpy(char *dst, char *src, size_t size);
size_t	ft_strlen(const char *s);

#endif
/******************************************************************************/
/*                     	DESCRIZIONE											  */
/* File: get_next_line.c | get_next_line_utils.c | get_next_line.h			  */
/* ---------------------													  */
/* Descrizione: 															  */
/* Questi file implementano la funzione get_next_line per la lettura		  */
/* incrementale da uno o piu' file descriptor.								  */
/*																			  */
/* Gestione FD:																  */
/* Il limite di 4096 file descriptor aperti è stato impostato per evitare	  */
/* l'esaurimento delle risorse del sistema. Tale limite è verificabile		  */
/* e configurabile attraverso il comando `ulimit`.							  */
/******************************************************************************/
/*----------------------------------------------------------------------------*/
/******************************************************************************/
/*						GESTIONE FD											  */
/* Gestione dei Limiti dei File Descriptor con `ulimit`:					  */
/* -----------------------------------------------------					  */
/* - Controllare il limite soft corrente: `ulimit -Sn`						  */
/*   Mostra il max FD aperti permessi attualmente per l'utente.				  */
/*																			  */
/* - Controllare il limite hard corrente: `ulimit -Hn`						  */
/*   Mostra il max FD aperti consentiti, modificabile solo da root.			  */
/*																			  */
/* - Impostare un nuovo limite soft: `ulimit -Sn <nuovo_limite>`			  */
/*   Permette di modificare il limite soft fino al limite hard.				  */
/*																			  */
/* - Impostare un nuovo limite hard (root): `ulimit -Hn <nuovo_limite>`		  */
/*   Root può aumentare il limite hard fino a un nuovo valore.				  */
/*																			  */
/* Nota:																	  */
/* Modifiche al limite soft sono temporanee, ristabilite al riavvio.		  */
/* Per cambiamenti permanenti, modificare /etc/security/limits.conf,		  */
/* dopo averlo fatto dovrete temere ripercussioni da Davide.				  */
/******************************************************************************/
/*----------------------------------------------------------------------------*/
