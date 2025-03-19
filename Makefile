

#--------------------------------------------------
#                  ENVIRONMENT
#--------------------------------------------------

#----- C language compiler -----
CPL=cc
CPL_FLAGS=-Wall -Wextra -Werror

#----- Program informations -----
PNAME=minishell

#----- RM Command -----
RM_FLAGS=-f
SMK_RM_FLAGS=-fr

#----- Sanitize flags -----
SAN_FLAGS=-fsanitize=address -fsanitize=leak


#--------------------------------------------------
#              SOURCES AND OBJECTS
#--------------------------------------------------

#----- Sources -----
SRCS=	./minishell.c \
		./shell/shell_signals.c \
		./shell/shell_clear.c \
		./shell/shell_init.c \
		./shell/shell_env.c \
		./shell/shell_start.c \
		./commands/cmd_debug.c \
		./commands/cmd_add.c \
		./commands/cmd_init.c \
		./commands/cmd_clear.c \
		./utils/util_string.c \
		./utils/util_errors.c \
		./builtins/pwd.c \
		./builtins/print_env.c \
		./builtins/cd.c \
		./builtins/echo.c \
		./builtins/unset.c \
		./builtins/builtin_utils.c \
		./builtins/export.c \
		./exec/exec_cmd.c \
		./exec/exec_utils.c \
		./exec/set_and_execute.c \
		./exec/exec_builtins.c \
		./prompt/pmt_tilde.c \
		./prompt/pmt_vars.c \
		./prompt/pmt_start.c \
		./prompt/pmt_parse.c \
		./prompt/pmt_clear.c \
		./prompt/pmt_debug.c \
		./prompt/pmt_init.c \
		./directories/dir_init.c \
		./directories/dir_disp.c \
		./directories/dir_clear.c \
		./directories/dir_nav.c \
		./signatures/sgn_welcome.c \
		./groups/grp_cmd.c \
		./groups/grp_init.c \
		./groups/grp_set.c \
		./groups/grp_clear.c \
		./groups/grp_uniq.c \
		./groups/grp_debug.c \
		./groups/grp_split.c \
		./groups/reader/grp_read_clear.c \
		./groups/reader/grp_read_extract.c \
		./groups/reader/grp_checkers.c \
		./groups/reader/grp_read_init.c \
		./groups/reader/grp_reader.c \
		./env/env.c \
		./env/env_utils.c \
		./token/tok_util.c \
		./token/tok_parse.c \
		./token/tok_init.c \
		./token/tok_clear.c \
		./token/tok_debug.c \
		./token/tok_error.c

#----- Objects -----
OBJS=$(SRCS:.c=.o)

#----- Objects (SMK) -----
SMK_OBJS_DIR=objs
SMK_OBJS=$(addprefix ./$(SMK_OBJS_DIR)/, $(notdir $(OBJS)))
VPATH = $(sort $(dir $(SRCS)))



#--------------------------------------------------
#              DEPENDENCIES (LIBS)
#--------------------------------------------------

#----- Lib: libft -----
LIBFT_NAME=libft.a
LIBFT_PATH=./libft/
LIBFT_LPATH=-L$(LIBFT_PATH)
LIBFT_LCALL=-lft
LIBFT_CALL=$(LIBFT_LPATH) $(LIBFT_LCALL)


#----- Common -----
DEPS_LIST=$(LIBFT_PATH)$(LIBFT_NAME) 
DEPS_CALLS=$(LIBFT_CALL) 

#----- External -----
EXT_DEPS=-lreadline

#--------------------------------------------------
#      LOADING BAR - ADVANCED MAKEFILE (AMK)
#--------------------------------------------------

#----- Counts -----
AMK_NB_FILES=$(words $(SRCS))
AMK_NB_ACTIONS=$(shell echo $$(( $(AMK_NB_FILES))))

#----- Vars -----
AMK_BARPOS=-1
AMK_WIDTH=50 
AMK_IS_INIT=0

#----- Functions -----

#Function 'init_bar': Setup the cursor position of the laoding bar
define init_bar
	@if [ $(AMK_IS_INIT) -eq 0 ]; then printf "\033[s"; fi
	$(eval AMK_IS_INIT := 1)
endef

#Function 'next_bar': Increment bar display to the next file
define next_bar
	$(eval AMK_BARPOS := $(shell echo $$(( $(AMK_BARPOS) + 1))))
	@printf "\033[u%-101s[\033[1m\033[33mWORKING\033[0m]" "$$(printf "[\033[1m\033[34mMAKEFILE\033[0m - \033[1m\033[36mCompiling\033[0m]: $$( printf "%.46s" "$@")")"
	@printf "\n["; \
	for i in `seq 1 $$(( (($(AMK_BARPOS) * 100) / $(AMK_NB_ACTIONS)) * $(AMK_WIDTH) / 100 ))`; \
	do \
	printf "\033[1m\033[34m#\033[0m"; \
	done; \
	printf "\033[u\n\033[$$(( $(AMK_WIDTH) + 1 ))C] \033[34m\033[1m$$(( (($(AMK_BARPOS) * 100) / $(AMK_NB_ACTIONS)) ))%%\033[0m (\033[34m\033[1m$(AMK_BARPOS)\033[0m/\033[34m\033[1m$(AMK_NB_FILES)\033[0m)\033[u"
endef

#Function 'final_bar': call when all done to set as finalresult
define final_bar
	$(eval AMK_BARPOS := $(shell echo $$(( $(AMK_BARPOS) + 1))))
	@printf "\033[u%-101s[\033[1m\033[34mOK\033[0m]        " "$$(printf "[\033[1m\033[34mMAKEFILE\033[0m - \033[1m\033[36mCompiling\033[0m]: $(PNAME)")"
	@printf "\033[s\n"; \
	for i in `seq 1 $$(( $(AMK_WIDTH) * 2 ))`; \
	do \
	printf " "; \
	done; \
	printf "\033[u\033s"
endef


#--------------------------------------------------
#                COMPILING RULES
#--------------------------------------------------

#----- Main Rules -----
all: $(PNAME)

$(PNAME): $(DEPS_LIST) $(SMK_OBJS_DIR)/ $(SMK_OBJS)
	$(eval NB_BARPOS := $(AMK_NB_FILES))
	$(call init_bar)
	$(call next_bar)
	@$(CPL) $(CPL_FLAGS) $(if $(SAN_ACTIVE), $(SAN_FLAGS)) $(DEPS_LIST) $(SMK_OBJS) $(DEPS_CALLS) $(EXT_DEPS) -o $@
	$(call final_bar)
	@printf "\n\033[s"

sanitize: fclean
	@printf "%-101s\033[s[\033[1m\033[33mWORKING\033[0m]" "$$(printf "[\033[1m\033[34mMAKEFILE\033[0m - \033[1m\033[36mCompiling\033[0m]: Compiling with Sanitize")"
	@printf "\033[u[\033[1m\033[34mOK\033[0m]        \n\033[s"
	@$(MAKE) --no-print-directory SAN_ACTIVE=true

$(SMK_OBJS_DIR)/%.o: %.c
	$(call init_bar)
	$(call next_bar)
	@$(CPL) $(CPL_FLAGS) -I./ -c $< -o $@
	@sleep 0.000000

#----- Libs Rules -----
$(LIBFT_PATH)$(LIBFT_NAME):
	@printf "\n%-123s\033[s[\033[1m\033[33mWORKING\033[0m]" "$$(printf "[\033[1m\033[34mMAKEFILE\033[0m - \033[1m\033[36mCompiling\033[0m]: '\033[1m\033[4m\033[36mlibft.a\033[24m\033[0m' compiling started")"
	@printf "\033[u[\033[1m\033[34mOK\033[0m]        \n\033[s"
	@$(MAKE) --no-print-directory -C $(LIBFT_PATH)
	@printf "%-123s\033[s[\033[1m\033[33mWORKING\033[0m]" "$$(printf "[\033[1m\033[34mMAKEFILE\033[0m - \033[1m\033[36mCompiling\033[0m]: '\033[1m\033[4m\033[36mlibft.a\033[24m\033[0m' compiling ended")"
	@printf "\033[u[\033[1m\033[34mOK\033[0m]        \n\033[s\n"


#--------------------------------------------------
#                CLEANING RULES
#--------------------------------------------------
clean:
	@printf "%-101s\033[s[\033[1m\033[33mWORKING\033[0m]" "$$(printf "[\033[1m\033[34mMAKEFILE\033[0m - \033[1m\033[36mClean\033[0m]: Cleaning object files")"
	@rm $(RM_FLAGS) $(SMK_OBJS)
	@printf "\033[u[\033[1m\033[34mOK\033[0m]        \n\033[s"
	@printf "\n%-123s\033[s[\033[1m\033[33mWORKING\033[0m]" "$$(printf "[\033[1m\033[34mMAKEFILE\033[0m - \033[1m\033[36mClean\033[0m]: '\033[1m\033[4m\033[36mlibft.a\033[24m\033[0m' cleaning started")"
	@printf "\033[u[\033[1m\033[34mOK\033[0m]        \n\033[s"
	@$(MAKE) --no-print-directory -C $(LIBFT_PATH) clean
	@printf "%-123s\033[s[\033[1m\033[33mWORKING\033[0m]" "$$(printf "[\033[1m\033[34mMAKEFILE\033[0m - \033[1m\033[36mClean\033[0m]: '\033[1m\033[4m\033[36mlibft.a\033[24m\033[0m' cleaning ended")"
	@printf "\033[u[\033[1m\033[34mOK\033[0m]        \n\033[s\n"

fclean: clean
	@printf "%-101s\033[s[\033[1m\033[33mWORKING\033[0m]" "$$(printf "[\033[1m\033[34mMAKEFILE\033[0m - \033[1m\033[36mFclean\033[0m]: Removing all generated files")"
	@rm $(RM_FLAGS) $(PNAME)
	@printf "\033[u[\033[1m\033[34mOK\033[0m]        \n\033[s"
	@printf "%-101s\033[s[\033[1m\033[33mWORKING\033[0m]" "$$(printf "[\033[1m\033[34mMAKEFILE\033[0m - \033[1m\033[36mFclean\033[0m]: Removing object folder")"
	@rm $(SMK_RM_FLAGS) $(SMK_OBJS_DIR)/
	@printf "\033[u[\033[1m\033[34mOK\033[0m]        \n\033[s"
	@printf "\n%-123s\033[s[\033[1m\033[33mWORKING\033[0m]" "$$(printf "[\033[1m\033[34mMAKEFILE\033[0m - \033[1m\033[36mFclean\033[0m]: '\033[1m\033[4m\033[36mlibft.a\033[24m\033[0m' full cleaning started")"
	@printf "\033[u[\033[1m\033[34mOK\033[0m]        \n\033[s"
	@$(MAKE) --no-print-directory -C $(LIBFT_PATH) fclean
	@printf "%-123s\033[s[\033[1m\033[33mWORKING\033[0m]" "$$(printf "[\033[1m\033[34mMAKEFILE\033[0m - \033[1m\033[36mFclean\033[0m]: '\033[1m\033[4m\033[36mlibft.a\033[24m\033[0m' full cleaning ended")"
	@printf "\033[u[\033[1m\033[34mOK\033[0m]        \n\033[s\n"


#--------------------------------------------------
#                EXTRA RULES
#--------------------------------------------------
$(SMK_OBJS_DIR)/:
	@printf "%-101s\033[s[\033[1m\033[33mWORKING\033[0m]" "$$(printf "[\033[1m\033[34mMAKEFILE\033[0m - \033[1m\033[36mExtra\033[0m]: Creating object folder")"
	@mkdir $(SMK_OBJS_DIR)/
	@printf "\033[u[\033[1m\033[34mOK\033[0m]        \n\033[s"

re: fclean all

.phony: all clean fclean re
