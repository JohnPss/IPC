package voult.ui;

import java.util.ArrayList;
import java.util.Optional;
import java.util.Scanner;

import voult.core.voult;
import voult.enums.StatusMissaoEnum;
import voult.enums.StatusSobreviventeEnum;
import voult.enums.TipoRecursoEnum;
import voult.model.Missao;
import voult.model.Recurso;
import voult.model.Sobrevivente;

public class Menu {

    public static void adicionarRecursoMenu(ArrayList<Recurso> recursos) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Selecione o nome do recurso que deseja adicionar: ");
        TipoRecursoEnum.exibirRecursos();

        final TipoRecursoEnum tipoRecursoFinal;
        TipoRecursoEnum tipoRecurso = null;

        while (tipoRecurso == null) {
            System.out.println("Digite o numero do tipo de recurso: ");
            int tipoRecursoInt = scanner.nextInt();
            try {
                tipoRecurso = TipoRecursoEnum.fromkey(tipoRecursoInt);
            } catch (IllegalArgumentException e) {
                System.out.println("Numero de tipo de recurso inválido. Digite novamente: ");
            }
        }
        tipoRecursoFinal = tipoRecurso;

        System.out.println("Digite a quantidade do recurso: ");
        int quantidade = scanner.nextInt();

        Recurso novoRecurso = new Recurso(tipoRecursoFinal, quantidade);

        Optional<Recurso> recursoExistente = recursos.stream()
                .filter(r -> r.getNome() == tipoRecursoFinal)
                .findFirst();

        if (recursoExistente.isPresent()) {
            try {
                recursoExistente.get().adicionarQuantidade(quantidade);
                System.out.println("Os valores foram adicionados ao existente.");
            } catch (Exception e) {
                System.out.println("Ops, Algo deu errado!");
            }
        } else {
            recursos.add(novoRecurso);
            System.out.println("Recurso adicionado com sucesso!");
        }
    }

    public static void setStatusMissao(Missao missao) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Status possiveis: ");
        StatusMissaoEnum.exibirStatus();

        StatusMissaoEnum status = null;

        while (status == null) {
            System.out.println("Digite o numero do status: ");
            int statusInt = scanner.nextInt();
            try {
                status = StatusMissaoEnum.fromkey(statusInt);
            } catch (IllegalArgumentException e) {
                System.out.println("Numero de tipo de status inválido. Digite novamente: ");
            }
        }

        missao.setStatus(status);
    }

    public void addSobreviventeMissaoPeloID(Missao missao, ArrayList<Sobrevivente> sobreviventes) {
        if (sobreviventes.isEmpty()) {
            throw new IllegalStateException(
                    "Não há sobreviventes cadastrados no vault. Adicione sobreviventes primeiro!");
        }

        System.out.println("Sobreviventes disponíveis para a missão:");
        for (Sobrevivente sobrevivente : sobreviventes) {
            if (sobrevivente.getStatus() == StatusSobreviventeEnum.ATIVO ||
                    sobrevivente.getStatus() == StatusSobreviventeEnum.FERIDO) {
                System.out.println("ID: " + sobrevivente.getIndentificador() + " - Nome: " + sobrevivente.getNome()
                        + " - Status: " + sobrevivente.getStatus());
            }
        }

        System.out.println("Digite o ID do sobrevivente que deseja adicionar à missão:");
        Scanner scanner = new Scanner(System.in);
        String idSobrevivente = scanner.nextLine();

        Optional<Sobrevivente> sobrevivente = sobreviventes.stream()
                .filter(s -> s.getIndentificador().equals(idSobrevivente))
                .findFirst();

        if (sobrevivente.isPresent()) {
            if (sobrevivente.get().getStatus() == StatusSobreviventeEnum.DOENTE ||
                    sobrevivente.get().getStatus() == StatusSobreviventeEnum.MORTO) {
                System.out.println("O sobrevivente selecionado não pode participar da missão devido ao status: "
                        + sobrevivente.get().getStatus());
                return;
            }

            if (missao.adicionarSobrevivente(idSobrevivente)) {
                System.out.println("Sobrevivente adicionado com sucesso!");
            } else {
                System.out.println("Sobrevivente já adicionado à missão!");
            }
        } else {
            throw new IllegalArgumentException("Sobrevivente com ID '" + idSobrevivente + "' não encontrado!");
        }
    }

}
