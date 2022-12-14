PGDMP     &    &                z            Projects    14.3    14.3     ?           0    0    ENCODING    ENCODING        SET client_encoding = 'UTF8';
                      false            ?           0    0 
   STDSTRINGS 
   STDSTRINGS     (   SET standard_conforming_strings = 'on';
                      false            ?           0    0 
   SEARCHPATH 
   SEARCHPATH     8   SELECT pg_catalog.set_config('search_path', '', false);
                      false            ?           1262    16663    Projects    DATABASE     g   CREATE DATABASE "Projects" WITH TEMPLATE = template0 ENCODING = 'UTF8' LOCALE = 'Russian_Russia.1251';
    DROP DATABASE "Projects";
                nile_pg    false            ?            1259    16664 	   locations    TABLE     ?   CREATE TABLE public.locations (
    location_id integer NOT NULL,
    city character varying(30),
    street_address character varying(45),
    postal_code character varying(6) NOT NULL
);
    DROP TABLE public.locations;
       public         heap    postgres    false            ?            1259    16667    locations_location_id_seq    SEQUENCE     ?   CREATE SEQUENCE public.locations_location_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;
 0   DROP SEQUENCE public.locations_location_id_seq;
       public          postgres    false    209            ?           0    0    locations_location_id_seq    SEQUENCE OWNED BY     W   ALTER SEQUENCE public.locations_location_id_seq OWNED BY public.locations.location_id;
          public          postgres    false    210            ?            1259    16668    projects    TABLE     ?   CREATE TABLE public.projects (
    id integer NOT NULL,
    appointment character varying(30),
    customer character varying(60),
    location_id integer NOT NULL
);
    DROP TABLE public.projects;
       public         heap    postgres    false            ?            1259    16671    objects_id_seq    SEQUENCE     ?   CREATE SEQUENCE public.objects_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;
 %   DROP SEQUENCE public.objects_id_seq;
       public          postgres    false    211            ?           0    0    objects_id_seq    SEQUENCE OWNED BY     B   ALTER SEQUENCE public.objects_id_seq OWNED BY public.projects.id;
          public          postgres    false    212            a           2604    16672    locations location_id    DEFAULT     ~   ALTER TABLE ONLY public.locations ALTER COLUMN location_id SET DEFAULT nextval('public.locations_location_id_seq'::regclass);
 D   ALTER TABLE public.locations ALTER COLUMN location_id DROP DEFAULT;
       public          postgres    false    210    209            b           2604    16673    projects id    DEFAULT     i   ALTER TABLE ONLY public.projects ALTER COLUMN id SET DEFAULT nextval('public.objects_id_seq'::regclass);
 :   ALTER TABLE public.projects ALTER COLUMN id DROP DEFAULT;
       public          postgres    false    212    211            ?          0    16664 	   locations 
   TABLE DATA                 public          postgres    false    209   ?       ?          0    16668    projects 
   TABLE DATA                 public          postgres    false    211   {       ?           0    0    locations_location_id_seq    SEQUENCE SET     H   SELECT pg_catalog.setval('public.locations_location_id_seq', 21, true);
          public          postgres    false    210                        0    0    objects_id_seq    SEQUENCE SET     =   SELECT pg_catalog.setval('public.objects_id_seq', 20, true);
          public          postgres    false    212            d           2606    16675    locations locations_pkey 
   CONSTRAINT     _   ALTER TABLE ONLY public.locations
    ADD CONSTRAINT locations_pkey PRIMARY KEY (location_id);
 B   ALTER TABLE ONLY public.locations DROP CONSTRAINT locations_pkey;
       public            postgres    false    209            f           2606    16677    projects objects_pkey 
   CONSTRAINT     S   ALTER TABLE ONLY public.projects
    ADD CONSTRAINT objects_pkey PRIMARY KEY (id);
 ?   ALTER TABLE ONLY public.projects DROP CONSTRAINT objects_pkey;
       public            postgres    false    211            g           2606    16678 !   projects objects_location_id_fkey    FK CONSTRAINT     ?   ALTER TABLE ONLY public.projects
    ADD CONSTRAINT objects_location_id_fkey FOREIGN KEY (location_id) REFERENCES public.locations(location_id) NOT VALID;
 K   ALTER TABLE ONLY public.projects DROP CONSTRAINT objects_location_id_fkey;
       public          postgres    false    211    3172    209            ?   ?  x????kA???+??6d???,?<??
?zמ
?
?}?=?P?Pm?ċ?4ٚ&?Ϳ?????۝ݦ??Y<$??e>????{????Ɠm?????z?????Nco????????g=?ز??5?Æ_`s??;????7??&??%?:?d??5F?1?.w?????	???79t
???	??@??1?"e}???M???v|a????s??e[v??=?K??mmD???+c??I?a??&?P?????e~&0???e?&l?y?eB>N??L?	"?!bمk?*j????+?Q~???C5i???J?*?????;?(?Qg??iD?S?<Ȃ?????%}??E???	mC=???X??))?????#ɚ?2y??N??l
???f?v# h]?3?x?8i?Ma???|z???:?????ҍp?6???㳊:?{??hc??2S??1?ɑ
V?v͚?????bnK?1???3??ס?I-???:??\?#3`z?yE8??!!F?HQ&_?????r??|?n?B~?"?JoMسtp????^???	u?
?S?:7????~?$X?h٤a\??	?*??Qӣ????+.?U]?N????X?	~??>???L??%?,???.W<;?g?[?CGr??w]F???z?A?æ??(h???	?实Sq???^?l? ?`?е???[?5      ?   ?  x????JQ??}????J3?Vq?B? 
V} K??RĕS/oP?h??V(??h??r^?'1I??Y?!ߟI?'5???2???	??:?0??Y*?糙?e3346=?6?e?XB????gz4??^??l?(>?X???1?8??????p?%??O0c][?,?&{ϲ?U?{9?
?o	X?	?,@Pҳ;?+yq?]J?
????-B?ز?X7?HuV?~@?Jv?I?T????/?ĺT????E???>?M?45?s?x-?;??N??1???$?"If??)^t?n^?J?}????_???֠????0?(*e???~??_P??Kذ??h?3??C?1%b?H/???k?0??؄C?L6??Ƞ5??F??\??{Z{?k4??nF?????? Z?A<??nwS?F0?_n h????P??_G??Y??4Ȇ?TK??z
???u?C???>?Z?x??vϣ5w???Q?ۜ?MJ?	?????4NL???????/???D? ????     