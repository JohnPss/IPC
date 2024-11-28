package lab03.src;

import java.util.Scanner;

public class App {
    public static void main(String[] args) throws Exception {
        Scanner scanner = new Scanner(System.in);
        Curso curso = null;
        while (true) {
            System.out.println("1 - Criar Curso");
            System.out.println("2 - Adicionar Disciplina");
            System.out.println("3 - Adicionar Aluno");
            System.out.println("4 - Adicionar Professor");
            System.out.println("5 - Listar Disciplinas");
            System.out.println("6 - Listar Alunos");
            System.out.println("7 - Listar Professores");
            System.out.println("8 - Sair");
            int opcao = scanner.nextInt();

            switch (opcao) {
                case 1:
                    System.out.println("Digite o nome do curso");
                    String nomeCurso = scanner.next();
                    curso = new Curso(nomeCurso);
                    System.out.println("Curso criado com sucesso");
                    break;
                case 2:
                    if (curso == null) {
                        System.out.println("Crie um curso primeiro");
                        break;
                    }

                    System.out.println("Digite o nome da disciplina");
                    String nomeDisciplina = scanner.next();
                    System.out.println("Digite a carga horaria da disciplina");
                    int CH = scanner.nextInt();
                    System.out.println("Digite o nome do professor");
                    String nomeProfessor = scanner.next();
                    System.out.println("Digite a titulação do professor");
                    String titulacao = scanner.next();
                    System.out.println("Digite o curso do professor");
                    String cursoP = scanner.next();
                    System.out.println("Digite o endereço do professor");
                    String enderecoProfessor = scanner.next();

                    curso.addDiciplina(new Diciplina(nomeDisciplina, CH,
                            new Professor(nomeProfessor, enderecoProfessor, titulacao, cursoP)));
                    break;
                case 3:
                    if (curso == null) {
                        System.out.println("Crie um curso primeiro");
                        break;
                    }

                    System.out.println("Digite o nome do aluno");
                    String nomeAluno = scanner.next();
                    System.out.println("Digite o endereço do aluno");
                    String enderecoAluno = scanner.next();
                    System.out.println("Digite a matricula do aluno");
                    int matricula = scanner.nextInt();

                    curso.addAluno(new Aluno(nomeAluno, enderecoAluno, matricula));
                    break;
                case 4:
                    if (curso == null) {
                        System.out.println("Crie um curso primeiro");
                        break;
                    }

                    System.out.println("Digite o nome do professor");
                    String nomeProf = scanner.next();
                    System.out.println("Digite a titulação do professor");
                    String titula = scanner.next();
                    System.out.println("Digite o curso do professor");
                    String cursoProf = scanner.next();
                    System.out.println("Digite o endereço do professor");
                    String enderecoProf = scanner.next();

                    curso.addProfessor(new Professor(nomeProf, enderecoProf, titula, cursoProf));

                    break;
                case 5:
                    if (curso == null) {
                        System.out.println("Crie um curso primeiro");
                        break;
                    }

                    curso.imprimirDiciplinas();

                    break;
                case 6:
                    if (curso == null) {
                        System.out.println("Crie um curso primeiro");
                        break;
                    }

                    curso.imprimirAlunos();

                    break;
                case 7:

                    if (curso == null) {
                        System.out.println("Crie um curso primeiro");
                        break;
                    }

                    curso.imprimirProfessores();

                    break;
                case 8:
                    System.out.println("Saindo...");
                    System.exit(0);
                    break;

                default:
                    System.out.println("Opção inválida");
                    break;
            }
        }

    }
}
