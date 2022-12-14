PGDMP     '                     z            postgres    13.8    13.8     l           0    0    ENCODING    ENCODING        SET client_encoding = 'UTF8';
                      false            m           0    0 
   STDSTRINGS 
   STDSTRINGS     (   SET standard_conforming_strings = 'on';
                      false            n           0    0 
   SEARCHPATH 
   SEARCHPATH     8   SELECT pg_catalog.set_config('search_path', '', false);
                      false            o           1262    13622    postgres    DATABASE     S   CREATE DATABASE postgres WITH TEMPLATE = template0 ENCODING = 'UTF8' LOCALE = 'C';
    DROP DATABASE postgres;
                postgres    false            p           0    0    DATABASE postgres    COMMENT     N   COMMENT ON DATABASE postgres IS 'default administrative connection database';
                   postgres    false    3183                        3079    16384 	   adminpack 	   EXTENSION     A   CREATE EXTENSION IF NOT EXISTS adminpack WITH SCHEMA pg_catalog;
    DROP EXTENSION adminpack;
                   false            q           0    0    EXTENSION adminpack    COMMENT     M   COMMENT ON EXTENSION adminpack IS 'administrative functions for PostgreSQL';
                        false    2            ?            1259    16421 	   locations    TABLE     ?   CREATE TABLE public.locations (
    location_id integer NOT NULL,
    city character varying(30),
    street_address character varying(45),
    postal_code character varying(6) NOT NULL
);
    DROP TABLE public.locations;
       public         heap    postgres    false            ?            1259    16424    locations_location_id_seq    SEQUENCE     ?   CREATE SEQUENCE public.locations_location_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;
 0   DROP SEQUENCE public.locations_location_id_seq;
       public          postgres    false    201            r           0    0    locations_location_id_seq    SEQUENCE OWNED BY     W   ALTER SEQUENCE public.locations_location_id_seq OWNED BY public.locations.location_id;
          public          postgres    false    202            ?            1259    16426    projects    TABLE     ?   CREATE TABLE public.projects (
    id integer NOT NULL,
    appointment character varying(30),
    customer character varying(60),
    location_id integer NOT NULL
);
    DROP TABLE public.projects;
       public         heap    postgres    false            ?            1259    16429    objects_id_seq    SEQUENCE     ?   CREATE SEQUENCE public.objects_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;
 %   DROP SEQUENCE public.objects_id_seq;
       public          postgres    false    203            s           0    0    objects_id_seq    SEQUENCE OWNED BY     B   ALTER SEQUENCE public.objects_id_seq OWNED BY public.projects.id;
          public          postgres    false    204            ?           2604    16431    locations location_id    DEFAULT     ~   ALTER TABLE ONLY public.locations ALTER COLUMN location_id SET DEFAULT nextval('public.locations_location_id_seq'::regclass);
 D   ALTER TABLE public.locations ALTER COLUMN location_id DROP DEFAULT;
       public          postgres    false    202    201            ?           2604    16432    projects id    DEFAULT     i   ALTER TABLE ONLY public.projects ALTER COLUMN id SET DEFAULT nextval('public.objects_id_seq'::regclass);
 :   ALTER TABLE public.projects ALTER COLUMN id DROP DEFAULT;
       public          postgres    false    204    203            f          0    16421 	   locations 
   TABLE DATA           S   COPY public.locations (location_id, city, street_address, postal_code) FROM stdin;
    public          postgres    false    201   ?       h          0    16426    projects 
   TABLE DATA           J   COPY public.projects (id, appointment, customer, location_id) FROM stdin;
    public          postgres    false    203   ?       t           0    0    locations_location_id_seq    SEQUENCE SET     H   SELECT pg_catalog.setval('public.locations_location_id_seq', 21, true);
          public          postgres    false    202            u           0    0    objects_id_seq    SEQUENCE SET     =   SELECT pg_catalog.setval('public.objects_id_seq', 20, true);
          public          postgres    false    204            ?           2606    16434    locations locations_pkey 
   CONSTRAINT     _   ALTER TABLE ONLY public.locations
    ADD CONSTRAINT locations_pkey PRIMARY KEY (location_id);
 B   ALTER TABLE ONLY public.locations DROP CONSTRAINT locations_pkey;
       public            postgres    false    201            ?           2606    16436    projects objects_pkey 
   CONSTRAINT     S   ALTER TABLE ONLY public.projects
    ADD CONSTRAINT objects_pkey PRIMARY KEY (id);
 ?   ALTER TABLE ONLY public.projects DROP CONSTRAINT objects_pkey;
       public            postgres    false    203            ?           2606    16437 !   projects objects_location_id_fkey    FK CONSTRAINT     ?   ALTER TABLE ONLY public.projects
    ADD CONSTRAINT objects_location_id_fkey FOREIGN KEY (location_id) REFERENCES public.locations(location_id) NOT VALID;
 K   ALTER TABLE ONLY public.projects DROP CONSTRAINT objects_location_id_fkey;
       public          postgres    false    3040    201    203            f   !  x??TKn?0\???
A??w?a?? 14E? `????K?+<ިCIimY?deJ?g?%??????6???e4???????!??:?d??v????y&??E?e~Ď?jzK?=њ??(c5	?Y??_e??Q???U?s?=-:6?^4X?????A????s=?j ??lp???r3)?7(???a?-?S?ng???v??UFo8z?u?4??*m??	~bkM/IbR???x8??&???
???9?Kv??o??Bji??<c]0???l???@78???5i?{<?)???\???)???9zr?w??5? ?<?,sV#%.?????_?Y????Ǡk?[+?D?i?BM?K???O???D
???r1?m4{F@o?l?Q'ǰ?!?T`?X?gڙ?!?L?%K??C??|?qB?	gdp\?|???m???Er*??߳?d]????P6Pr?eN???????R?r????NY???`*D34p?z??I@fr(߯?aU7?dm??G???jf???r9?/|F??m?iBz?b?E4????_s??_?w??      h   ?  x?}R?nS1<{?"?????~w?=r??$? Ф=?Z)?*?8@)\?BPڦ????/r?"?^d???g??~.??~??|?k]??.?6?????l?78\???`?g???M.??8r???S]?p?ȯq???&k?O??/ ??K?????+?&y
?gۧ?z#$[5?0?Kx?-?
?7&\?????"l?F?'??U?3Lw60?7u?sz?W?ڻ??r 8vL??;???R??3??y??`???ՓO???e䘢H4=?fO???>ߤ?y?%?F??-?{zq??L??k`??????ǡM??zÎ???Be????????\?x?m}?`eZ??o P*?`S??B???"??ٖPfVh 4?}?/5?UA?p)P1??7??f06????*?,ċ?HKt?KL?c?6/??p"N?ʗuq7+(?;A?????~?E\??Sr??Β??Ż3?F;???? ???_?.     