import java.util.ArrayList;

public class ListaCliente {
    ArrayList<Cliente> clientes;

    public void adicionarCliente(String nome, String cpf) {
        clientes.add(new Cliente(nome, cpf));
    }

    public Cliente buscarCliente(String cpf) {
        return clientes.stream().filter(cliente -> cliente.getCpf().equals(cpf))
                .findFirst().orElse(null);
    }

    public void exibirClientes() {
        for (Cliente c : clientes) {
            c.toString();
        }
    }
}
