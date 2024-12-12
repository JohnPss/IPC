import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class App {
    public static void main(String[] args) throws Exception {
        Scanner scan = new Scanner(System.in);
        List<Gerente> gerentes = new ArrayList<>();
        List<Desenvolvedor> desenvolvedores = new ArrayList<>();
        List<TechLead> techLeads = new ArrayList<>();

        int opcao;
        while (true) {
            System.out.println("Escolha uma opção:");
            System.out.println("1. Adicionar Gerente");
            System.out.println("2. Adicionar Desenvolvedor");
            System.out.println("3. Adicionar TechLead");
            System.out.println("4. Listar todos");
            System.out.println("5. Sair");
            opcao = scan.nextInt();
            scan.nextLine();

            switch (opcao) {
                case 1:
                    System.out.println("Nome: ");
                    String nomeG = scan.nextLine();
                    System.out.println("Salario base: ");
                    int salarioBG = scan.nextInt();
                    System.out.println("Numero de equipes: ");
                    int numEG = scan.nextInt();
                    gerentes.add(new Gerente(numEG, nomeG, salarioBG));

                    break;
                case 2:

                    System.out.println("Nome: ");
                    String nomeD = scan.nextLine();
                    System.out.println("Salario base: ");
                    int salarioBD = scan.nextInt();
                    System.out.println("Linguagem: ");
                    String linguagem = scan.nextLine();
                    desenvolvedores.add(new Desenvolvedor(linguagem, nomeD, salarioBD));

                    break;
                case 3:
                    System.out.println("Nome: ");
                    String nomeTL = scan.nextLine();
                    System.out.println("Salario base: ");
                    int salarioBTC = scan.nextInt();
                    System.out.println("Numero de equipes: ");
                    int numETL = scan.nextInt();
                    System.out.println("Linguagem: ");
                    String linguagemTL = scan.nextLine();
                    techLeads.add(new TechLead(linguagemTL, numETL, nomeTL, salarioBTC));
                    break;
                case 4:

                    if (!gerentes.isEmpty()) {
                        System.out.println("Gerentes:");
                        for (Gerente gerente : gerentes) {
                            System.out.println(gerente.descricao());
                        }
                    } else {
                        System.out.println("Nenhum gerente cadastrado.");
                    }
                    System.out.println("------------------------");

                    if (!desenvolvedores.isEmpty()) {
                        System.out.println("Desenvolvedores:");
                        for (Desenvolvedor desenvolvedor : desenvolvedores) {
                            System.out.println(desenvolvedor.descricao());
                        }
                    } else {
                        System.out.println("Nenhum desenvolvedor cadastrado.");
                    }

                    System.out.println("------------------------");

                    if (!techLeads.isEmpty()) {
                        System.out.println("TechLeads:");
                        for (TechLead techLead : techLeads) {
                            System.out.println(techLead.descricao());
                        }
                    } else {
                        System.out.println("Nenhum TechLead cadastrado.");
                    }

                    System.out.println("------------------------");

                    break;
                case 5:
                    break;
                default:
                    break;
            }
        }
    }
}