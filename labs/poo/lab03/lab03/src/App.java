package lab03.src;

import java.util.Scanner;

public class App {
    public static void main(String[] args) throws Exception {
        Scanner scanner = new Scanner(System.in);
        Curso curso = null;
        while (true) {
            System.out.println("\n=============================");
            System.out.println("         MENU PRINCIPAL      ");
            System.out.println("=============================");
            System.out.println("1 - Criar Curso");
            System.out.println("2 - Adicionar Disciplina");
            System.out.println("3 - Adicionar Aluno");
            System.out.println("4 - Adicionar Professor");
            System.out.println("5 - Listar Disciplinas");
            System.out.println("6 - Listar Alunos");
            System.out.println("7 - Listar Professores");
            System.out.println("8 - Sair");
            System.out.println("=============================");
            System.out.print("Escolha uma opção: ");
            int opcao = scanner.nextInt();
            System.out.println();

            switch (opcao) {
                case 1:
                    System.out.println("Digite o nome do curso:");
                    String nomeCurso = scanner.next();
                    curso = new Curso(nomeCurso);
                    System.out.println("\nCurso criado com sucesso!");
                    break;

                case 2:
                    if (curso == null) {
                        System.out.println("Erro: Crie um curso primeiro.");
                        break;
                    }

                    if (!curso.professoresExiste()) {
                        System.out.println("Erro: Adicione um professor primeiro.");
                        break;
                    }

                    if (curso.getProfessores().isEmpty()) {
                        System.out.println("Erro: Adicione um professor primeiro.");
                        break;
                    }

                    System.out.println("Digite o nome da disciplina:");
                    String nomeDisciplina = scanner.next();
                    System.out.println("Digite a carga horária da disciplina:");
                    int CH = scanner.nextInt();
                    curso.imprimirProfessor();
                    System.out.println("Digite o ID do professor:");
                    int idProfessor = scanner.nextInt();

                    while (!curso.idProfessorExiste(idProfessor)) {
                        System.out.println("Erro: ID inválido. Digite um ID válido:");
                        idProfessor = scanner.nextInt();
                    }

                    curso.addDiciplina(new Diciplina(nomeDisciplina, CH,
                            curso.getProfessores().get(idProfessor)));
                    System.out.println("\nDisciplina adicionada com sucesso!");
                    break;

                case 3:
                    if (curso == null) {
                        System.out.println("Erro: Crie um curso primeiro.");
                        break;
                    }

                    System.out.println("Digite o nome do aluno:");
                    String nomeAluno = scanner.next();
                    System.out.println("Digite o endereço do aluno:");
                    String enderecoAluno = scanner.next();

                    curso.addAluno(new Aluno(nomeAluno, enderecoAluno));
                    System.out.println("\nAluno adicionado com sucesso!");
                    break;

                case 4:
                    if (curso == null) {
                        System.out.println("Erro: Crie um curso primeiro.");
                        break;
                    }

                    System.out.println("Digite o nome do professor:");
                    String nomeProf = scanner.next();
                    System.out.println("Digite a titulação do professor:");
                    String titula = scanner.next();
                    System.out.println("Digite o curso do professor:");
                    String cursoProf = scanner.next();
                    System.out.println("Digite o endereço do professor:");
                    String enderecoProf = scanner.next();

                    curso.addProfessor(new Professor(nomeProf, enderecoProf, titula, cursoProf));
                    System.out.println("\nProfessor adicionado com sucesso!");
                    break;

                case 5:
                    if (curso == null) {
                        System.out.println("Erro: Crie um curso primeiro.");
                        break;
                    }

                    curso.imprimirDiciplinas();
                    break;

                case 6:
                    if (curso == null) {
                        System.out.println("Erro: Crie um curso primeiro.");
                        break;
                    }

                    curso.imprimirAlunos();
                    break;

                case 7:
                    if (curso == null) {
                        System.out.println("Erro: Crie um curso primeiro.");
                        break;
                    }

                    curso.imprimirProfessores();
                    break;

                case 8:
                    System.out.println("Saindo... Até a próxima!");
                    scanner.close();
                    System.exit(0);
                    break;

                default:
                    System.out.println("Erro: Opção inválida. Tente novamente.");
                    break;
            }
        }
    }
}
